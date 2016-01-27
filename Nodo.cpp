//
//  Nodo.cpp
//  ListaConcatenata
//
//  Created by Salvatore  Polito on 26/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Nodo.hpp"
Nodo::Nodo() {
    data=0;
    next=0;
}

Nodo::Nodo(int _d) : data(_d) {
    next=0;
}

void Nodo::setData(int d){
    data=d;
}
void Nodo::setNext(Nodo &_next){
    this->next=&_next;
}

int Nodo::getData() const {
    return data;
}

Nodo* Nodo::getNext(){
    return next;
}

std::ostream& operator<< (std::ostream &os, Nodo &toprint) {
    os << toprint.getData() << " " ;
    
    return os;
}