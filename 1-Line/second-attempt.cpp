#include "second-attempt.h"


const TGAColor blue = TGAColor(0, 0, 255, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);


void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color)
{ 
    /**
     * 如果你希望以 x 或 y 轴中的某一个作为主要方向来按整数步进，
     * 另一个轴方向按斜率倍数步进，来绘制线，
     * 那么很容易会在另一个方向上跳过像素，使得线不连续
     * （而且这样必须从左往右画……从右往左直接跳过绘制了……
     *   所以显然下一次尝试需要同时考虑两个轴）
     */
    for (int x = x0; x <= x1; x++) {

        float t = (x - x0) / (float)(x1 - x0); 

        int y = y0 * (1. - t) + y1 * t; 

        image.set(x, y, color); 
    } 
}


int main(int argc, char** argv)
{
    TGAImage image(100, 100, TGAImage::RGB);

    line(10, 20, 60, 50, image, blue);

    line(20, 90, 90, 10, image, green);

    image.write_tga_file("output.tga");

    return 0;
}


// file ends here

