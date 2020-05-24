
int main(int argc, char** argv)
{
    TGAImage image(200, 200, TGAImage::RGB);

    // code here

    image.flip_vertically();
    image.write_tga_file("output.tga");

    return 0;
}


