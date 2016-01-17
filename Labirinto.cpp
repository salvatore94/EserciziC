//
//  Labirinto.cpp
//  Simulazione Labirinto 1
//
//  Created by Salvatore  Polito on 16/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Labirinto.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


Labirinto::Labirinto(){
//    srand(unsigned(time(0)));
    for(int i=0; i<=10; i++){
        for(int j=0; j<=10; j++)
            tabella[i][j]= rand()%2;
    }
    
    tabella[5][5]=true;
    for (int i=0; i<11; ++i)
        tabellaInsetti[i]=0;
    nInsetti=0;
}

//Labirinto::~Labirinto(){
//    for (int i=nInsetti; i>=0; --i)
//    if(tabellaInsetti[i])
//        delete tabellaInsetti[i];
//}

//void Labirinto::Run(int _cicli) {
//    for(int i=1;i<=_cicli; i++)
//        for(int j=0; j<=nInsetti; j++){
//            if(tabellaInsetti[j]){
//            if(!this->isOut(j))
//                tabellaInsetti[j]->muovi();
//            else{
//                std::cout << tabellaInsetti[j]->getIdentificativo() << " è uscito dopo " << i << " cicli!" << std::endl;
//                return;}
//            }
//        }
//}

void Labirinto::Run(int _n){
    for(int i=0; i<_n; i++)
        for(int j=0; j<nInsetti; ++j)
            if(tabellaInsetti[j]!=0 && this->isOut(j)==false)
                tabellaInsetti[j]->muovi();
            else if ( this->isOut(j)==true){
               std::cout << tabellaInsetti[j]->getIdentificativo() << " è uscito dopo " << i << " cicli!" << std::endl;
                return;}
}

void Labirinto::stampaLabirinto(std::ostream &os) const {
    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            if(!this->isAccessible(i, j))
                os << "-";
            else
                os<< " ";
        }
        os << std::endl;
    }
    os<< std::endl;
}

void Labirinto::stampaListaInsetti(std::ostream &os) {
    for (int i=0;i<=nInsetti; i++)
        if(tabellaInsetti[i])
        os << this->tabellaInsetti[i]->getIdentificativo() << std::endl;
}

bool Labirinto::isAccessible(int _x, int _y) const {
    return tabella[_x][_y];
}

bool Labirinto::isOut(int _pos) const {
    if(tabellaInsetti[_pos]){
    if(tabellaInsetti[_pos]->getX() <0 || tabellaInsetti[_pos]->getX()>10 || tabellaInsetti[_pos]->getY()<0 || tabellaInsetti[_pos]->getY()>10)
        return true;
    else
        return false;
    }
    return true;
}

void Labirinto::addInsetto(Insetto *toadd) {
    tabellaInsetti[nInsetti++]=toadd;
}