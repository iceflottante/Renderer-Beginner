#include "main.h"


const TGAColor blue = TGAColor(0, 0, 255, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);


void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color)
{
    /**
     * 在前一步的基础上进一步优化每次绘制前 y 的计算，提升性能
     * 基本思想：提前缓存部分值，简化每次循环时的一些计算
     *
     * 并且这里以 0.5 为阈值步进 y，比上次的靠类型转换舍弃浮点
     * 要效果好，具体可以对比 ThirdAttempt 和 FourAttempt
     * 画出来的线效果。
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

    float derror = std::abs(dy / (float)dx);
    float error = 0;
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

        if (error > 0.5f)
        {
            y += y1 > y0 ? 1 : -1;
            error -= 1;
        }
    } 
}


int main(int argc, char** argv)
{
    TGAImage image(100, 100, TGAImage::RGB);

    line(10, 20, 60, 50, image, blue);

    line(90, 20, 50, 90, image, green);

    image.write_tga_file("output.tga");

    return 0;
}


// file ends here

