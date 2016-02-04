//
//  Store.cpp
//  Gestione Applicazioni (1)
//
//  Created by Salvatore  Polito on 02/02/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Store.hpp"
Store::~Store() {
    for(int i=this->getSize(); i>=0; i--)
        delete listaApplicazioni[i];
}

int Store::cercaPerId(long n) {
    for (int i=0; i<this->getSize(); i++)
        if (listaApplicazioni[i]->getId()==n)
            return i;
    return -1;
}

void Store::addApplicazione() {
    Applicazione *a1= new Applicazione;
    listaApplicazioni.push_back(a1);
}

void Store::removeApplicazione() {
    long x=0;
    std::cout <<"Inserire ID dell'applicazione da rimuovere: ";
    std::cin >> x;
    x = this->cercaPerId(x);
    if(x!=-1) {
        delete listaApplicazioni[x];
        listaApplicazioni.erase(listaApplicazioni.begin() + x);
        std::cout << "\nRimossa!" << std::endl;
    }
    else
        std::cout << "\nApplicazione non trovata!" << std::endl;
}

void Store::stampaListaApplicazioni() {
    for(int i=0; i<this->getSize(); i++)
        std::cout << listaApplicazioni[i];
}

Applicazione& Store::getApplicazione(int n) {
    if (n < this->getSize())
        return *listaApplicazioni[n];
    else
        return *listaApplicazioni[0];
}

int Store::getSize() {
    return static_cast<int>(listaApplicazioni.size());
}