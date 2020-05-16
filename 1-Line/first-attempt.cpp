#include "first-attempt.h"


const TGAColor blue = TGAColor(0, 0, 255, 255);


void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
    /**
     * 如果 step 比较大，比如对于 100 x 100 的图片设为 0.1，
     * 那么就会很容易出现断线，甚至完全是间隔点组成线
     */
    float step = 0.01;

    for (float t = 0; t < 1; t += step)
    {
        int x = x0 + (x1 - x0) * t;
        int y = y0 + (y1 - y0) * t;
        image.set(x, y, color);
    }
}


int main(int argc, char** argv)
{
    TGAImage image(100, 100, TGAImage::RGB);

    line(10, 20, 60, 50, image, blue);

    image.write_tga_file("output.tga");

    return 0;
}


// file ends here

