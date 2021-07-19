#include <iostream>
#include "../Lib/model.h"
#include "../Lib/line.h"


void triangle(Vec2i v0, Vec2i v1, Vec2i v2, TGAImage &image, TGAColor &color)
{
    // 过滤三点共线的情况 (也可以按线来画)
    if (v0.y == v1.y && v1.y == v2.y) return;

    // 冒泡排序
    if (v0.y > v1.y) std::swap(v0, v1);
    if (v1.y > v2.y) std::swap(v1, v2);
    if (v0.y > v1.y) std::swap(v0, v1);

    int total_height = v2.y - v0.y;
    int a1_height = v1.y - v0.y;
    int a2_height = v2.y - v1.y;
    int b_height = v2.y - v0.y;

    for (int i = 0; i <= total_height; i++)
    {
        bool is_part_two = i >= a1_height;

        float ya = is_part_two ? ((float) (i - a1_height) / a2_height) : ((float)i / a1_height);
        float yb = (float)i / total_height;

        Vec2i A = is_part_two ? (v1 + (v2 - v1) * ya) : (v0 + (v1 - v0) * ya);
        Vec2i B = v0 + (v2 - v0) * yb;

        if (A.x > B.x)
        {
            std::swap(A, B);
        }

        for (int j = A.x; j <= B.x; j++)
        {
            image.set(j, v0.y + i, white);
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

