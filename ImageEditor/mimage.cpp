#include "mimage.h"

MImage::MImage(QImage i)
{
    width = i.width();
    height = i.height();
    img = new QImage(i);
}

QImage MImage::getImage()
{
    return *img;
}

MImage::~MImage()
{
    img->~QImage();
}

/** Линейное растяжение гистограммы яркости */
void MImage::lineExt(int minX, int minY, int maxX, int maxY)
{
    for(int i = minX; i < maxX; i+=10)
        for(int j = minY; j < maxY; ++j)
            img->setPixel(i, j, 0);
}

/** Поканальное растяжение гистограммы */
void MImage::channelExt(int minX, int minY, int maxX, int maxY)
{
    // TODO
}

/** Фильтр Гаусса */
void MImage::gauss(int minX, int minY, int maxX, int maxY)
{
    // TODO
}

/** Повышение резкости */
void MImage::sharpening(int minX, int minY, int maxX, int maxY)
{
    // TODO
}

/** Серый мир */
void MImage::grayWorld(int minX, int minY, int maxX, int maxY)
{
    // TODO
}

/** Медианная фильтрация */
void MImage::median(int minX, int minY, int maxX, int maxY)
{
    // TODO
}

/** Сепарабельный фильтр Гаусса */
void MImage::sepGauss(int minX, int minY, int maxX, int maxY)
{
    // TODO
}

/** Спецэффект «Волны» */
void MImage::waves(int minX, int minY, int maxX, int maxY)
{
    // TODO
}

/** Спецэффект «Стекло» */
void MImage::glass(int minX, int minY, int maxX, int maxY)
{
    // TODO
}
