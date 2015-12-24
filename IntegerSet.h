#ifndef INTEGERSET_H
#define INTEGERSET_H

#include<iostream>

class IntegerSet {
    bool integerset[100];


public:
    IntegerSet();
    IntegerSet(int);
    bool get(int posizione) const {return integerset[posizione];}
    void setInteger(int posizione, bool valore) { integerset[posizione]=valore;}

    IntegerSet unionOfIntegerSet(const IntegerSet&) const;
    IntegerSet intersectionOfIntegerSet (const IntegerSet&) const;
    IntegerSet& insertElement (int);
    IntegerSet& deleteElement (int);

    IntegerSet& setPrint (std::ostream&);
    bool isEqualTo (const IntegerSet&) const;
};

#endif
