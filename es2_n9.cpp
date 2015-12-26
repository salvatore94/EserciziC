#include<iostream>
using std::cout;
using std::endl;

#include"Punto2D.h"
#include"Punto2D.cpp"
#include"Punto3D.cpp"


int main () {
    Punto2D p1, p2(5,7);

    cout << "Coordinate P1: " << "( " << p1.getX() <<", "<< p1.getY() <<")" << endl;
    cout << "Coordinate P2: " << "( " << p2.getX() <<", "<< p2.getY() <<")" << endl;
    cout << "Distanza tra P1 e P2: " << p1.distanza(p2) << endl;

    p1.setX(10);
    p1.setY(4);
    cout << "Nuove Coordinate P1: " << "( " << p1.getX() <<", "<< p1.getY() <<")" << endl;
    cout <<"Nuova distanza tra P1 e P2: " <<p1.distanza(p2) <<endl;


    Punto3D p3, p4(4,6,2);
    cout << "Coordinate P3: " << "( " << p3.getX() <<", "<< p3.getY() <<", "<<p3.getZ() <<")" << endl;
    cout << "Coordinate P4: " << "( " << p4.getX() <<", "<< p4.getY() <<", "<<p4.getZ() <<")" << endl;
    cout << "Distanza tra P3 e P4: " << p3.distanza(p4) << endl;

    return 0;
}
