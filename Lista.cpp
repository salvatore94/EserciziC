//
//  Lista.cpp
//  ListaConcatenata
//
//  Created by Salvatore  Polito on 26/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Lista.hpp"
Lista::Lista() : lunghezza(0), next(0), current(0) {}

Lista::Lista(Nodo &first): Lista() {
    next=&first;
}

Nodo& Lista::spostaAvanti() {
    if (current == 0)
        current=next;
    else
        current=current->getNext();
    return *current ;
}

Nodo& Lista::getCurrent() {
    return *current;
}

void Lista::aggiungiNodo(Nodo &toadd){
    if(lunghezza==0) {
        next=&toadd;
        lunghezza++;
        this->spostaAvanti();
    }
    else {
        for (int i=1; i<lunghezza; ++i)
            this->spostaAvanti();
        current->setNext(toadd);
        lunghezza++;
    }
}
void Lista::rimuoviNodo(int _pos){
    Nodo *temp=0;
    if(_pos<=lunghezza) {
        for(int i=0; i<=_pos; i++)
            this->spostaAvanti();
        temp=current->getNext();
        for(int i=0; i<=_pos - 1 ; i++)
            this->spostaAvanti();
        current->setNext(*temp);
    }
}

int Lista::getLunghezza() const {
    return lunghezza;
}

Nodo& Lista::getNodo(int pos){
    if (pos<lunghezza) {
        for(int i=0; i<=pos; i++)
            this->spostaAvanti();
        return *current;
    }
    return *next;
}

std::ostream& operator<< (std::ostream &os, Lista &toprint){
    for(int i=0; i<toprint.getLunghezza(); i++)
        os<< toprint.getNodo(i);

    return os;
}

Lista& Lista::operator= (Lista &l2){
    l2.current=0;
//    next=l2.next;
//    ++lunghezza;
    for(int i=0; i<= l2.getLunghezza(); i++)
        this->aggiungiNodo(l2.spostaAvanti());
    
    return *this;
}

bool Lista::operator== (Lista &l2)  {
    if(lunghezza!=l2.getLunghezza())
        return false;
    else {
        for(int i=0; i<=lunghezza; i++) {
            this->spostaAvanti();
            l2.spostaAvanti();
            if(this->getCurrent().getData()!=l2.getCurrent().getData())
                return false;
        }
    }
    
    return true;
}

bool Lista::operator!= (Lista &l2) {
    if(*this==l2)
        return false;
    else
        return true;
}


