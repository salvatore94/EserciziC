#include"Punto2D.h"

Punto2D::Punto2D (int _x, int _y) {
    x=_x;
    y=_y;
}

Punto2D::Punto2D (const Punto2D &tocopy) {
    this->setX(tocopy.getX());
    this->setY(tocopy.getY());
}

double Punto2D::distanza (const Punto2D &p2) const {
    double distanza;
    distanza = sqrt(pow((p2.getX()-x), 2) + pow((p2.getY()-y), 2));
    return distanza;
}
