//
//  Matrice.cpp
//  Matrici Rettangolari
//
//  Created by Salvatore  Polito on 04/02/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Matrice.hpp"
void Matrice::crea (int r, int c) {
    data = new int*[r];
    for(int i=0; i<r; i++)
        data[i] = new int [c];
}

void Matrice::distruggi() {
    for(int i=0; i<this->getRighe(); i++)
        delete[] data[i];
    delete[] data;
}

bool Matrice::sameLen(Matrice &m) {
    if(this->getRighe() == m.getRighe() && this->getColonne() == m.getColonne())
        return true;
    else
        return false;
}

int Matrice::getRighe() {
    return nRighe;
}

int Matrice::getColonne() {
    return nColonne;
}

Matrice::Matrice() {
    nRighe=2;
    nColonne=2;
    
    this->crea(nRighe, nColonne);
    
    for(int i=0; i<nRighe; i++)
        for(int j=0; j<nColonne; j++)
            data[i][j]=0;
}

Matrice::Matrice(int r, int c) {
    nRighe=r;
    nColonne=c;
    
    this->crea(nRighe, nColonne);
    
    for(int i=0; i<nRighe; i++)
        for(int j=0; j<nColonne; j++)
            data[i][j]=0;
}

Matrice::Matrice(Matrice &m) {
    nRighe=m.getRighe();
    nColonne=m.getColonne();
    
    this->crea(nRighe, nColonne);
    
    for(int i=0; i<nRighe; i++)
        for(int j=0; j<nColonne; j++)
            data[i][j]=m.at(i, j);
}

Matrice::~Matrice() {
    this->distruggi();
}

int& Matrice::at(int r, int c) {
    if(r>=0 && r<this->getRighe() && c>=0 && r<this->getColonne())
        return data[r][c];
    else
        return data[0][0];
}

Matrice& Matrice::operator= (Matrice &tocopy) {
    this->distruggi();
    nRighe= tocopy.getRighe();
    nColonne= tocopy.getColonne();
    
    this->crea(nRighe, nColonne);
    
    for(int i=0; i<nRighe; i++)
        for(int j=0; j<nColonne; j++)
            data[i][j]=tocopy.at(i, j);
    
    return *this;
}

Matrice& Matrice::operator+ (Matrice &toadd) {
    if(this->sameLen(toadd)==true) {
        for(int i=0; i<nRighe; i++)
            for(int j=0; j<nColonne; j++)
                data[i][j] = ( data[i][j] + toadd.at(i, j) );
    }
    return *this;
}
Matrice& Matrice::operator- (Matrice &tosub) {
    if(this->sameLen(tosub)==true) {
        for(int i=0; i<nRighe; i++)
            for(int j=0; j<nColonne; j++)
                data[i][j] = ( data[i][j] - tosub.at(i, j) );
    }
    return *this;
}


std::istream& operator>> (std::istream &in, Matrice &m) {
    std::cout << "===============" << std::endl;
    for(int i=0; i<m.getRighe(); i++)
        for(int j=0; j<m.getColonne(); j++)
            in >> m.at(i, j);
    std::cout << "===============" << std::endl;
    return in;
}

std::ostream& operator<< (std::ostream &os, Matrice &m) {
    os << "===============" << std::endl;
    for(int i=0; i<m.getRighe(); i++) {
        for(int j=0; j<m.getColonne(); j++)
            os << m.at(i, j) << " ";
        os << std::endl;
    }
    os << "===============" << std::endl;
    return os;
}