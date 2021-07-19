#include "../Lib/tgaimage.h"
#include "../Lib/model.h"
#include "../Lib/line.h"


int width = 800;
int height = 800;



int main(int argc, char** argv)
{
    // just dumping the 2d scene (yay we have enough dimensions!)
    TGAImage scene(width, height, TGAImage::RGB);

    // scene "2d mesh"
    line(Vec2i(20, 34), Vec2i(744, 400), scene, red);
    line(Vec2i(120, 434), Vec2i(444, 400), scene, green);
    line(Vec2i(330, 463), Vec2i(594, 200), scene, blue);

    // screen line
    line(Vec2i(10, 10), Vec2i(790, 10), scene, white);

    scene.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    scene.write_tga_file("output.tga");

    return 0;
}

// file ends here

