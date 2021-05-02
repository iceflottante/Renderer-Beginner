#include "main.h"


void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color)
{
    /**
     * 若选择 x 轴为主轴步进整数，那么在要绘制的直线与主轴夹角小于 45 度，
     * 即斜率绝对值小于 1 时：
     *    - 交换起终点 x 和 y 值 (相当于转置图像)
     * 即可沿用之前的绘制方法。
     *
     * 同时，之前的绘制方法只能从左往右画，所以我们还需要在必要时：
     *    - 交换起终点
     *
     * 最后计算要绘制点的坐标时，需要按之前交换 x 和 y 值的样子再转置回来
     * 
     * (不过这里还缺少了边界情况的处理)
     */
    int dx = std::abs(x0 - x1);
    int dy = std::abs(y0 - y1);
    bool needTranspose = false;

    if (dx < dy)
    {
        std::swap(x0, y0);
        std::swap(x1, y1);
        needTranspose = true;
    }

    if (x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    for (int x = x0; x <= x1; x++) {

        float t = (x - x0) / (float)(x1 - x0); 

        int y = y0 * (1. - t) + y1 * t; 

        if (needTranspose)
        {
            image.set(y, x, color); 
        }
        else
        {
            image.set(x, y, color); 
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

