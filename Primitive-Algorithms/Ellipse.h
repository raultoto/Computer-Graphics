#ifndef ELLIPSE_H
#define ELLIPSE_H
#include<QOpenGLWidget>
#include<QOpenGLFunctions>
#include <algorithm>
#include "Shape.h"
class Ellipse:public Shape
{
public:
    Ellipse() {}
    inline int round (const float a) { return int (a + 0.5); }
    /* El siguiente procedimiento acepta valores que definen el centro
    * de la elipse y sus semiejes mayor y menor, calculando las
    * posiciones de la elipse mediante el algoritmo del punto medio.
    */
    inline void ellipsePlotPoints(int xCenter,int yCenter,int x,int y)
    {
        setPixel (xCenter +x,yCenter+y);
        setPixel (xCenter -x,yCenter+y);
        setPixel (xCenter +x,yCenter-y);
        setPixel (xCenter -x,yCenter-y);
    }
    inline void ellipseMidpoint (int xCenter, int yCenter, int Rx, int Ry)
    {
        int Rx2 = Rx * Rx;
        int Ry2 = Ry * Ry;
        int twoRx2 = 2 * Rx2;
        int twoRy2 = 2 * Ry2;
        int p;
        int x = 0;
        int y = Ry;
        int px = 0;
        int py = twoRx2 * y;
        void ellipsePlotPoints (int, int, int, int);
        //Dibujar el punto inicial en cada cuadrante.
        this->ellipsePlotPoints (xCenter, yCenter, x, y);
        // Región 1
        p = round (Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
        while (px < py) {
            x++;
            px += twoRy2;
            if (p < 0)
                p += Ry2 + px;
            else {
                y--;
                py -= twoRx2;
                p += Ry2 + px - py;
            }
            this->ellipsePlotPoints (xCenter, yCenter, x, y);
        }
        //region 2
        p = round (Ry2 * (x+0.5) * (x+0.5) + Rx2 * (y-1) * (y-1) - Rx2 * Ry2);
        while (y > 0) {
            y--;
            py -= twoRx2;
            if (p > 0)
                p += Rx2 - py;
            else {
                x++;
                px += twoRy2;
                p += Rx2 - py + px;
            }
            this->ellipsePlotPoints (xCenter, yCenter, x, y);
        }
    }


};
#endif // ELLIPSE_H
