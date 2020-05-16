#include "second-attempt.h"


const TGAColor blue = TGAColor(0, 0, 255, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);


void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color)
{ 
    /**
     * �����ϣ���� x �� y ���е�ĳһ����Ϊ��Ҫ������������������
     * ��һ���᷽��б�ʱ����������������ߣ�
     * ��ô�����׻�����һ���������������أ�ʹ���߲�����
     * ��������������������һ�������������ֱ�����������ˡ���
     *   ������Ȼ��һ�γ�����Ҫͬʱ���������ᣩ
     */
    for (int x = x0; x <= x1; x++) {

        float t = (x - x0) / (float)(x1 - x0); 

        int y = y0 * (1. - t) + y1 * t; 

        image.set(x, y, color); 
    } 
}


int main(int argc, char** argv)
{
    TGAImage image(100, 100, TGAImage::RGB);

    line(10, 20, 60, 50, image, blue);

    line(20, 90, 90, 10, image, green);

    image.write_tga_file("output.tga");

    return 0;
}


// file ends here

