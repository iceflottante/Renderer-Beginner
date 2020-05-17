#include "main.h"
#include "Lib/model.h"


TGAColor white = TGAColor(255, 255, 255, 255);


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


int main()
{
    int width = 100;
    int height = 100;

    TGAImage image(width, height, TGAImage::RGB);

    Model model("../Assets/Models/african_head.obj");

    for (int i = 0; i < model.nfaces(); i++)
    {
        std::vector<int> face = model.face(i);

        for (int j = 0; j < 3; j++)
        {
            Vec3f v0 = model.vert(face[j]);
            Vec3f v1 = model.vert(face[(j + 1) % 3]);

            int x0 = (v0.x + 1.f) * width / 2;
            int y0 = (v0.y + 1.f) * height / 2;

            int x1 = (v1.x + 1.f) * width / 2;
            int y1 = (v1.y + 1.f) * height / 2;

            line(x0, y0, x1, y1, image, white);
        }
    }

    return 0;
}


// file ends here

