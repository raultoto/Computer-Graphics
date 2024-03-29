#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#include <iostream>
#include <QColor>
#include <cmath>
#include<QOpenGLWidget>
#include<QOpenGLFunctions>
#include <QtWidgets>
#include <QDebug>
#include <QMouseEvent>
#include "Line.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Polygon.h"
#include "beziercurve.h"
#include <list>
#define RGB_MIN 1
#define RGB_MAX 255
class OpenglWidget: public QOpenGLWidget
{
    Q_OBJECT
    //CONSTANTES GLOBAIS
    const float color[5][3] = {{1.0, 1.0, 1.0}, //branco
                               {1.0, 0.0, 0.0}, //vermelho
                               {0.0, 1.0, 0.0}, //verde
                               {0.0, 0.0, 1.0}, //azul
                               {1.0, 1.0, 0.0} }; // amarelo

    int MouseAux=0;
    QPoint MousePoint;
    QVector<QRect> rects;
public:
    OpenglWidget(QWidget *parent=nullptr);
//protected:
    void initializeGL() override;
    void paintGL() override;
    //void resizeGL(int w,int h) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void setPixel (float xCoord, float yCoord)
    {
        glBegin (GL_POINTS);
            glVertex2i (xCoord, yCoord);
        glEnd ( );
    }
    int typeShape,colorChosed=0,angle=30,tx=0,ty=0,sx=0,sy=0;
    void resetValues();
    //void mousePressEvent(QMouseEvent *event)override;
    //void mouseMoveEvent(QMouseEvent *event)override;
private:
    void qColorToRGB(const QColor &C,float &r,float &g,float &b) const;
    float normalize_0_1(float val,float min,float max)const;
    float lineSize=3.0;
    int xAtPress=0,yAtPress=0,xAtRelease=0,yAtRelease=0;
    QPoint initPos;
    QPoint finalPos;
    vector<wcPt3D> vec;
    int x,y;
};

#endif // OPENGLWIDGET_H
