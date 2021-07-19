#include "tgaimage.h"
#include "model.h"



void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor &color)
{
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

void line(Vec2i a, Vec2i b, TGAImage& image, TGAColor& color)
{
    line(a.x, a.y, b.x, b.y, image, color);
}

// file ends here

