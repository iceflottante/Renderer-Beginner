#include "main.h"


/**
 * 当然，这里的 color 我们也可以改成使用指针，不进行复制，还可以进一步提升性能
 * 包括编译时加上优化标志如 -O3，不过这些都是 C/C++ 的代码优化范畴，不再赘述
 */
void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor &color)
{
    /**
     * 前面我们使用 0.5 作为 error 的比较阈值
     * 乘以 2 再乘以 dx，我们可以用整型替换掉过程中的浮点数，
     * 完成进一步优化
     *
     * 其实，这就是 The Bresenham Line-Drawing Algorithm 的全整型实现
     */
    int dx = std::abs(x0 - x1);
    int dy = std::abs(y0 - y1);
    bool needTranspose = false;

    if (dx < dy)
    {
        std::swap(x0, y0);
        std::swap(x1, y1);
        std::swap(dx, dy);
        needTranspose = true;
    }

    if (x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    int derror = std::abs(dy) * 2;
    int error = 0;
    int y = y0;

    for (int x = x0; x <= x1; x++) {

        if (needTranspose)
        {
            image.set(y, x, color); 
        }
        else
        {
            image.set(x, y, color); 
        }

        error += derror;

        if (error > dx)
        {
            y += y1 > y0 ? 1 : -1;
            error -= dx * 2;
        }
    } 
}


int main(int argc, char** argv)
{
    TGAImage image(100, 100, TGAImage::RGB);

    line(50, 50, 10, 10, image, blue);
    line(50, 50, 10, 20, image, green);
    line(50, 50, 10, 30, image, blue);
    line(50, 50, 10, 40, image, green);
    line(50, 50, 10, 50, image, blue);
    line(50, 50, 10, 60, image, green);
    line(50, 50, 10, 70, image, blue);
    line(50, 50, 10, 80, image, green);
    line(50, 50, 10, 90, image, blue);

    line(50, 50, 20, 90, image, blue);
    line(50, 50, 30, 90, image, blue);
    line(50, 50, 40, 90, image, blue);
    line(50, 50, 50, 90, image, blue);
    line(50, 50, 60, 90, image, blue);
    line(50, 50, 70, 90, image, blue);
    line(50, 50, 80, 90, image, blue);
    line(50, 50, 90, 90, image, blue);
    line(50, 50, 90, 90, image, blue);

    line(50, 50, 90, 80, image, green);
    line(50, 50, 90, 70, image, blue);
    line(50, 50, 90, 60, image, green);
    line(50, 50, 90, 50, image, blue);
    line(50, 50, 90, 40, image, green);
    line(50, 50, 90, 30, image, blue);
    line(50, 50, 90, 20, image, green);
    line(50, 50, 90, 10, image, blue);

    image.write_tga_file("output.tga");

    return 0;
}


// file ends here

