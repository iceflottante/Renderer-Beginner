#include <iostream>
#include <algorithm>
#include "../Lib/model.h"
#include "../Lib/line.h"


Vec3i cross(Vec3i v0, Vec3i v1)
{
    Vec3i result(v0.y * v1.z - v0.z * v1.y, v1.x * v0.z - v0.x * v1.z, v0.x * v1.y - v0.y * v1.x);
    return result;
}

Vec3i Vec2iToVec3i(Vec2i v)
{
    Vec3i result(v.x, v.y, 0);
    return result;
}


/**
 * 扫描线（sweep line）算法需要按顺序遍历顶点坐标，然后判定是否绘制，这是经典的单线程编程思维模式
 * 如果在现代的并行计算领域，同时会有成千上万的线程同时计算时，我们就需要转变思维方式
 * 直接判定一个像素坐标是否在图元的范围内，让多个像素同时运算，这时，我们便只需要直接考虑包围框判定的方式
 *
 * 这里我们使用重心坐标系（Barycentric Coordinate System）
 * 这里我们用到的重心坐标系可以看作是单位向量不等的三维直角坐标系上的一个表示平面的方程式组：
 * \vec{P} = x \vec{A} + y \vec{B} + z \vec{C}
 * x + y + z = 1
 * 这样，等式所表示的系数集合形成一个平面，而其中三个系数都大于 0 的为三角形内，其余都是三角形外
 * 不过，如何求出 x, y, z 呢
 * \vec{P} = x \vec{A} + (y - y) \vec{A} + (z - z) \vec{A} + y \vec{B} + z \vec{C}
 * \vec{P} = (x + y + z) \vec{A} + y (\vec{B} - \vec{A}) + z (\vec{C} - \vec{A})
 * \vec{P} = 1 \vec{A} + y \vec{AB} + z \vec{AC}
 * 0 = \vec{PA} + y \vec{AB} + z \vec{AC}
 * 有：
 * (1, y, z) * (PA.x, AB.x, AC.x) = 0
 * (1, y, z) * (PA.y, AB.y, AC.y) = 0
 * 即 (1, y, z) 与同时垂直于 (PA.x, AB.x, AC.x) (PA.y, AB.y, AC.y) 的向量平行
 * 后者可以通过叉乘得到
 */
Vec3i barycentricTemp(Vec2i p, Vec2i v0, Vec2i v1, Vec2i v2)
{
    Vec3i result = cross(Vec3i(v0.x - p.x, v1.x - v0.x, v2.x - v0.x), Vec3i(v0.y - p.y, v1.y - v0.y, v2.y - v0.y));

    if (result.x == 0) return Vec3i(-1, 1, 1);

    return result;
}

Vec3f barycentric(Vec2i p, Vec2i v0, Vec2i v1, Vec2i v2)
{
    Vec3i result = barycentricTemp(p, v0, v1, v2);

    return Vec3f(1.f - (result.y + result.z) / (float)result.x, (float)result.y / result.x, (float)result.z / result.x);
}


bool isPointInsideTriangle(Vec2i p, Vec2i v0, Vec2i v1, Vec2i v2)
{
    Vec3f result = barycentric(p, v0, v1, v2);

    if (result.x < 0 || result.y < 0 || result.z < 0)
    {
        return false;
    }

    return true;
}


void triangle(Vec2i v0, Vec2i v1, Vec2i v2, TGAImage &image, TGAColor &color)
{
    // 过滤三点共线的情况 (也可以按线来画)
    if (v0.y == v1.y && v1.y == v2.y) return;

    Vec2i AB = v1 - v0;
    Vec2i AC = v2 - v0;

    Vec2i boudingMax(
        std::max(v0.x, std::max(v1.x, std::max(v2.x, 0))),
        std::max(v0.y, std::max(v1.y, std::max(v2.y, 0)))
    );

    Vec2i boudingMin(
        std::min(v0.x, std::min(v1.x, std::min(v2.x, image.get_width()))),
        std::min(v0.y, std::min(v1.y, std::min(v2.y, image.get_height())))
    );

    for (int x = boudingMin.x; x < boudingMax.x; x++)
    {
        for (int y = boudingMin.y; y < boudingMax.y; y++)
        {
            if (isPointInsideTriangle(Vec2i(x, y), v0, v1, v2))
            {
                image.set(x, y, white);
            }
        }
    }
}


int main(int argc, char** argv)
{
    TGAImage image(200, 200, TGAImage::RGB);

    Vec2i t0[3] = {Vec2i(10, 70),   Vec2i(50, 160),  Vec2i(70, 80)}; 
    Vec2i t1[3] = {Vec2i(180, 50),  Vec2i(150, 1),   Vec2i(70, 180)}; 
    Vec2i t2[3] = {Vec2i(180, 150), Vec2i(120, 160), Vec2i(130, 180)}; 

    triangle(t0[0], t0[1], t0[2], image, red); 
    triangle(t1[0], t1[1], t1[2], image, white); 
    triangle(t2[0], t2[1], t2[2], image, green);

    image.flip_vertically();
    image.write_tga_file("output.tga");

    return 0;
}


// file ends here


