#include<iostream>
using std::cout;
using std::endl;

#include "ArrayDinamico.cpp"


int main () {
    ArrayDinamico a1(50);
    cout << "Dimensione di a1: " << a1.getDimValue() << endl;


    a1.at(10)=4;
    cout << "Valore dell'elemento in posizione 10: " << a1.getDataValue(10) << endl;

    //a1.setData(9, 46);
    a1.at(9)=46;
    cout << "Valore dell'elemento in posizione 9: " << a1.getDataValue(9) << endl;

    //a1.setData(12)=444;
    a1.at(12)=444;
    cout << "Valore dell'elemento in posizione 12: " << a1.getDataValue(12) << endl;


    a1.resize(80);

    cout << "Nuova dimensione di a1: " << a1.getDimValue() << endl;
    a1.at(79)=6;
    cout << "Valore dell'elemento in posizione 79: " << a1.getDataValue(79) << endl;
    cout << "Valore dell'elemento in posizione 12: " << a1.getDataValue(12) << endl;


     ArrayDinamico a2(100);
     cout << "Dimensione di a2: " << a2.getDimValue() << endl;
     a2=a1;
    //a2.at(10)=4;
     cout << "Nuova dimensione di a2: " << a2.getDimValue() << endl;
     cout << "Valore dell'elemento in posizione 12 di a2: " << a2.getDataValue(12) << endl;
     cout << "Valore dell'elemento in posizione 10 di a2: " << a2.getDataValue(10) << endl;


     a1=a1;
     cout << "Valore dell'elemento in posizione 12 di a1: " << a1.getDataValue(12) << endl;
    return 0;

}
