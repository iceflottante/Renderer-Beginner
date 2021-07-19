#include "tgaimage.h"


TGAColor red = TGAColor(255, 0, 0, 255);
TGAColor green = TGAColor(0, 255, 0, 255);
TGAColor blue = TGAColor(0, 0, 255, 255);
TGAColor white = TGAColor(255, 255, 255, 255);


void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor& color);
void line(Vec2i a, Vec2i b, TGAImage& image, TGAColor& color);

