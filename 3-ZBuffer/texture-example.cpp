#include <iostream>
#include <algorithm>
#include "../Lib/model.h"
#include "../Lib/tgaimage.h"


Vec3i cross(Vec3i v0, Vec3i v1)
{
    Vec3i result(v0.y * v1.z - v0.z * v1.y, v1.x * v0.z - v0.x * v1.z, v0.x * v1.y - v0.y * v1.x);
    return result;
}

Vec3f crossf(Vec3f v0, Vec3f v1)
{
    Vec3f result(v0.y * v1.z - v0.z * v1.y, v1.x * v0.z - v0.x * v1.z, v0.x * v1.y - v0.y * v1.x);
    return result;
}

Vec3f normalize(Vec3f *v)
{
    float l = sqrt(v -> x * v -> x + v -> y * v -> y + v -> z * v -> z);

    v->x = v->x / l;
    v->y = v->y / l;
    v->z = v->z / l;

    return *v;
}


Vec3f sub(Vec3f v0, Vec3f v1)
{
    Vec3f result(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z);
    return result;
}

Vec3i barycentricTemp(Vec2i p, Vec2i v0, Vec2i v1, Vec2i v2)
{
    Vec3i result = cross(Vec3i(v0.x - p.x, v1.x - v0.x, v2.x - v0.x), Vec3i(v0.y - p.y, v1.y - v0.y, v2.y - v0.y));

    if (result.x == 0) return Vec3i(-1, 1, 1);

    return result;
}

Vec3f barycentric(Vec2i p, Vec2i v0, Vec2i v1, Vec2i v2)
{
    Vec3i result = barycentricTemp(p, v0, v1, v2);

    return Vec3f(1.f - (result.y + result.z) / (float)result.x, (float)result.y / result.x, (float)result.z / result.x);
}


void triangle(Vec3f v0, Vec3f v1, Vec3f v2, Vec2f vt0, Vec2f vt1, Vec2f vt2, TGAImage &image, Model *model, float *zbuffer)
{
    // �������㹲�ߵ���� (Ҳ���԰�������)
    if (v0.y == v1.y && v1.y == v2.y) return;
    int width = image.get_width();
    int height = image.get_height();

    Vec2f boudingMax(
        std::fmax(v0.x, std::fmax(v1.x, std::fmax(v2.x, 0))),
        std::fmax(v0.y, std::fmax(v1.y, std::fmax(v2.y, 0)))
    );

    Vec2f boudingMin(
        std::fmin(v0.x, std::fmin(v1.x, std::fmin(v2.x, width))),
        std::fmin(v0.y, std::fmin(v1.y, std::fmin(v2.y, height)))
    );

    for (int x = boudingMin.x; x < boudingMax.x; x++)
    {
        for (int y = boudingMin.y; y < boudingMax.y; y++)
        {
            Vec3f result = barycentric(Vec2i(x, y), Vec2i(v0.x, v0.y), Vec2i(v1.x, v1.y), Vec2i(v2.x, v2.y));

            if (result.x < 0 || result.y < 0 || result.z < 0)
            {
                continue;
            }

            float z = result.x * v0.z + result.y * v1.z + result.z * v2.z;
            Vec2f uv(result.x * vt0.x + result.y * vt1.x + result.z * vt2.x, result.x * vt0.y + result.y * vt1.y + result.z * vt2.y);

            if (zbuffer[y * width + x] <= z)
            {
                zbuffer[y * width + x] = z;
                image.set(x, y, model -> diffuse(uv));
            }
        }
    }
}


Vec3f world2screen(Vec3f p, int w, int h)
{
    return Vec3f((p.x + 1.f) * w / 2, (p.y + 1.f) * h / 2, p.z);
}


int main(int argc, char** argv)
{
    std::cout << argc << "\n" << argv[1] << std::endl;

    Model* model = NULL;

    if (argc == 2)
    {
        model = new Model(argv[1]);
    }
    else
    {
        return 1;
    }

    int width = 800;
    int height = 800;
    Vec3f lightDirection(0.f, 0.f, 1.f);


    // initialize z buffer
    float* zbuffer = new float[width * height];
    for (int i = 0; i < width * height; i++)
    {
        zbuffer[i] = std::numeric_limits<int>::min();
    }


    TGAImage image(width, height, TGAImage::RGB);

    for (int i = 0; i < model -> nfaces(); i++)
    {
        std::vector<int> face = model -> face(i);

        Vec3f n = crossf(
            sub(model->vert(face[0]), model->vert(face[1])),
            sub(model->vert(face[0]), model->vert(face[2]))
        );

        float intensity = normalize(&n) * lightDirection;

        if (intensity > 0)
        {
			triangle(
				world2screen(model-> vert(face[0]), width, height),
				world2screen(model-> vert(face[1]), width, height),
				world2screen(model-> vert(face[2]), width, height),
                model->uv(i, 0),
                model->uv(i, 1),
                model->uv(i, 2),
				image,
                model,
                zbuffer
			);
        }
    }

    image.flip_vertically();
    image.write_tga_file("output.tga");

    return 0;
}


// file ends here

