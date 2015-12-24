#include<iostream>


#include"IntegerSet.h"

IntegerSet::IntegerSet () {
    for(int i=0; i!=100; ++i)
        this->setInteger(i, false);
}
IntegerSet::IntegerSet(int posizione) : IntegerSet::IntegerSet() {
    this->insertElement(posizione);
}

IntegerSet IntegerSet::unionOfIntegerSet (const IntegerSet &integer2) const {
        IntegerSet unionset;

        for (int i=0; i!=100; ++i) {
            if (integerset[i]== true)
                unionset.setInteger(i, true);
            if (integer2.get(i) == true)
                unionset.setInteger(i, true);
            }

        return unionset;
}

IntegerSet IntegerSet::intersectionOfIntegerSet (const IntegerSet &integer2) const {
        IntegerSet intersection;

        for (int i=0; i!=100; ++i)
            if ((this->get(i)== true) && (integer2.get(i)==true))
                intersection.setInteger(i, true);

        return intersection;
}

IntegerSet& IntegerSet::insertElement (int posizione) {
        this->setInteger(posizione, true);

        return *this;
}

IntegerSet& IntegerSet::deleteElement (int posizione) {
        this->setInteger(posizione, false);

        return *this;
}

IntegerSet& IntegerSet::setPrint (std::ostream &os){
    int count=0;
    for(int i=0; i!=100; ++i)
        if (this->get(i)== true) {
            ++count;
        os << i << " " ;
        }
    if (count==0)
        os << "-";

    return *this;
}

bool IntegerSet::isEqualTo (const IntegerSet &integer2) const {
    for (int i=0; i!=100; ++i)
        if (this->get(i) != integer2.get(i))
            return false;
    return true;
}
