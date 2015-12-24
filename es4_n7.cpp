#include<iostream>
using std::cout;
using std::endl;

#include"IntegerSet.cpp"


int main () {

    IntegerSet s1, s2(40);
    cout << "Gli array contengono: " << endl
         << "s1: ";
         s1.setPrint(cout);
         cout << endl
         <<"s2: " ;
          s2.setPrint(cout);
          cout << endl
         << "Cambio i valori ..." << endl;

    s1.insertElement(55);
    s2.insertElement(4);
    s1.insertElement(12);
    s2.deleteElement(40);

    cout << "Gli array contengono: " << endl << "s1: ";
         s1.setPrint(cout);
         cout << endl <<"s2: " ;
          s2.setPrint(cout);
          cout << endl;


   return 0;
}
