#include "main.h"


const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);


int main(int argc, char** argv)
{
    // (0, 0) is at the left-top
    TGAImage image(100, 100, TGAImage::RGB);

    image.set(0, 10, red);
    image.set(0, 11, red);

    image.flip_vertically();

    image.set(0, 10, blue);
    image.set(0, 11, blue);

    image.write_tga_file("output.tga");

    return 0;
}


// file ends here

