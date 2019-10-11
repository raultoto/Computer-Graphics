#ifndef LINE_H
#define LINE_H
#include<QOpenGLWidget>
#include<QOpenGLFunctions>
#include <algorithm>
#include "Shape.h"
class Line:public Shape
{
public:
    Line() {}
    //Draw line if X distance is greater than Y
    void bresenhamX(int x0, int y0, int x1, int y1, int dx, int dy)
    {
        int i, j, k;
        i = 2 * dy - dx;
        j = 2 * dy;
        k = 2 * (dy - dx);
        if (!(x0 < x1)) {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        setPixel(x0, y0);
        while (x0 < x1) {
            if (i < 0)
                i += j;
            else {
                if (y0 < y1)
                    ++y0;
                else
                    --y0;
                i += k;
            }
            ++x0;
            setPixel(x0, y0);
        }
    }
    //Draw line if X distance is lesser than Y
    void bresenhamY(int x0, int y0, int x1, int y1, int dx, int dy)
    {
        int i, j, k;
        i = 2 * dx - dy;
        j = 2 * dx;
        k = 2 * (dx - dy);
        if (!(y0 < y1)) {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        setPixel(x0, y0);
        while (y0 < y1) {
            if (i < 0)
                i += j;
            else {
                if (x0 > x1)
                    --x0;
                else
                    ++x0;
                i += k;
            }
            ++y0;
            setPixel(x0, y0);
        }
    }
    //Called by mouse(), will call the appropriate function depending on the length of the X and Y axis
    void bresenham(int x0, int y0, int x1, int y1)

    {
        int dx = abs(x1 - x0);
        int dy = abs(y1 - y0);

        if (dx >= dy)
            this->bresenhamX(x0, y0, x1, y1, dx, dy);
        else
            this->bresenhamY(x0, y0, x1, y1, dx, dy);
    }
};

#endif // LINE_H
