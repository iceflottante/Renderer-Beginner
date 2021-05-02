#include "../Lib/tgaimage.h"
#include "../Lib/model.h"


void draw1D(int x, TGAImage &image, TGAColor &color)
{
    for (int i = 0; i < 16; i++)
    {
        image.set(x, i, color);
    }
}

void line(int x0, int y0, int x1, int y1, int height, TGAImage &image, TGAColor &color, int ybuffer[])
{
    if (x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    float k = (y1 - y0) / (float) (x1 - x0);

    for (int x = x0; x <= x1; x++) {
        float y = y0 + (x - x0) * k;

        if (y < ybuffer[x])
        {
            continue;
        }

        ybuffer[x] = y;
        draw1D(x, image, color);
    } 
}

void line(Vec2i a, Vec2i b, int height, TGAImage& image, TGAColor& color, int ybuffer[])
{
    line(a.x, a.y, b.x, b.y, height, image, color, ybuffer);
}


void printBuffer(int ybuffer[], int width, int height, TGAImage& image)
{
    for (int x = 0; x < width; x++)
    {
        int a = ybuffer[x] / 3;
        TGAColor color(a, a, a);
        draw1D(x, image, color);
    }
}


TGAColor red = TGAColor(255, 0, 0, 255);
TGAColor green = TGAColor(0, 255, 0, 255);
TGAColor blue = TGAColor(0, 0, 255, 255);
TGAColor white = TGAColor(255, 255, 255, 255);


const int width = 800;
const int height = 16;


int main(int argc, char** argv)
{
    // just dumping the 2d scene (yay we have enough dimensions!)
    TGAImage render(width, height, TGAImage::RGB);
    TGAImage buffer(width, height, TGAImage::RGB);


    // initialize y buffer
    int ybuffer[width];
    printf("std::numberic_limits<int>::min(): %d", std::numeric_limits<int>::min());
    for (int i = 0; i < width; i++)
    {
        ybuffer[i] = std::numeric_limits<int>::min();
    }


    line(Vec2i(20, 34), Vec2i(744, 400), height, render, red, ybuffer);
    render.write_tga_file("output1.tga");
    printBuffer(ybuffer, width, height, buffer);
    buffer.write_tga_file("buffer1.tga");

    line(Vec2i(120, 434), Vec2i(444, 400), height, render, green, ybuffer);
    render.write_tga_file("output2.tga");
    printBuffer(ybuffer, width, height, buffer);
    buffer.write_tga_file("buffer2.tga");

    line(Vec2i(330, 463), Vec2i(594, 200), height, render, blue,  ybuffer);
    render.write_tga_file("output3.tga");
    printBuffer(ybuffer, width, height, buffer);
    buffer.write_tga_file("buffer3.tga");

    return 0;
}

// file ends here

