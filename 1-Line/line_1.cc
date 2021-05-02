#include "main.h"


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

