#include "Punto2D.h"

class Punto3D : public Punto2D {
    int z;

public:
    Punto3D () : Punto3D (0,0,0) {};
    Punto3D (int _x, int _y, int _z) : Punto2D(_x,_y) {z=_z;}

    int getZ () const {return z;};
    void setZ(int _z) {z=_z;}

    double distanza (const Punto3D&) const;
};

double Punto3D::distanza (const Punto3D &p2) const {
    double distanza;
    distanza= sqrt((pow((p2.getX()-(this->getX())), 2) + pow((p2.getY()-(this->getY())), 2) + pow((p2.getZ()-(this->getZ())), 2)));

    return distanza;
}
