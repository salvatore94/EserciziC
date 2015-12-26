#ifndef PUNTO2D_H
#define PUNTO2D_H

//#include "Punto2D.cpp"
#include<cmath>

class Punto2D {
    int x, y;

public:
    Punto2D () : Punto2D(0,0) {};
    Punto2D (int, int);

    Punto2D (const Punto2D&); //copy constructor

    void setX(int val) {x=val;};
    void setY(int val) {y=val;};

    int getX() const {return x;};
    int getY() const {return y;};

    double distanza (const Punto2D&) const;
};
#endif
