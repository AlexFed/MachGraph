#ifndef MIMAGE_H
#define MIMAGE_H

#include <QPixmap>

class MPoint
{
    unsigned short R,G,B,Y,U,V;

    MPoint()
    {
        R = G = B = Y = U = V = 0;
    }

    inline void setRGB(unsigned int rgb)
    {
        setRGB( (rgb>>16)%256, (rgb>>8)%256, rgb%256);
    }

    inline void setRGB(unsigned short r, unsigned short g, unsigned short b)
    {
        R = r; G = g; B = b;
        Y = ( (  66 * R + 129 * G +  25 * B + 128) >> 8) +  16;
        U = ( ( -38 * R -  74 * G + 112 * B + 128) >> 8) + 128;
        V = ( ( 112 * R -  94 * G -  18 * B + 128) >> 8) + 128;
    }

    inline void setYUV(unsigned int yuv)
    {
        setYUV( (yuv>>16)%256, (yuv>>8)%256, yuv%256);
    }

    inline void setYUV(int y, int u, int v)
    {
        Y = y; U = u; V = v;
        unsigned short C = Y - 16, D = U - 128, E = V - 128;
        R = (( 298 * C           + 409 * E + 128) >> 8)&255;
        G = (( 298 * C - 100 * D - 208 * E + 128) >> 8)&255;
        B = (( 298 * C + 516 * D           + 128) >> 8)&255;
    }

};

class MImage
{
    int height, width;
    QImage *img;
public:
    MImage(QImage i);
    ~MImage();

    QImage getImage();
    void lineExt(int minX, int minY, int maxX, int maxY);
    void channelExt(int minX, int minY, int maxX, int maxY);
    void gauss(int minX, int minY, int maxX, int maxY);
    void sharpening(int minX, int minY, int maxX, int maxY);
    void grayWorld(int minX, int minY, int maxX, int maxY);
    void median(int minX, int minY, int maxX, int maxY);
    void sepGauss(int minX, int minY, int maxX, int maxY);
    void waves(int minX, int minY, int maxX, int maxY);
    void glass(int minX, int minY, int maxX, int maxY);
};

#endif // MIMAGE_H
