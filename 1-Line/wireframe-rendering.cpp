#include "main.h"
#include "../Lib/model.h"


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


int main(int argc, char** argv)
{
    Model* model = NULL;

    if (argc == 2) {
        model = new Model(argv[1]);
    } else {
        return 1;
    }

    int width = 800;
    int height = 800;

    TGAImage image(width, height, TGAImage::RGB);

    for (int i = 0; i < model -> nfaces(); i++)
    {
        std::vector<int> face = model -> face(i);

        for (int j = 0; j < 3; j++)
        {
            Vec3f v0 = model -> vert(face[j]);
            Vec3f v1 = model -> vert(face[(j + 1) % 3]);

            int x0 = (v0.x + 1.f) * width / 2;
            int y0 = (v0.y + 1.f) * height / 2;

            int x1 = (v1.x + 1.f) * width / 2;
            int y1 = (v1.y + 1.f) * height / 2;

            line(x0, y0, x1, y1, image, white);
        }
    }

    image.flip_vertically();

    image.write_tga_file("output.tga");

    return 0;
}


// file ends here
