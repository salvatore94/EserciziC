//
//  Sala.cpp
//  Biglietteria Cinema
//
//  Created by Salvatore  Polito on 25/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Sala.hpp"
Sala::Sala() {
    this->liberaTutto();
}

void Sala::liberaTutto(){
    for(int i=0; i<20; i++)
        for(int j=0; j<10; j++)
            this->listaPosti[i][j]=0;
}

void Sala::setCodice (char _s){
    if(_s == 'A' || _s == 'B' || _s == 'C' || _s == 'D')
        codice=_s;
}
void Sala::setOrarioFilm(const std::string &orario){
    orarioFilm=orario;
}
void Sala::setNomeFilm (const std::string &nome){
    nomeFilm=nome;
}

char Sala::getCodice() const{
    return codice;
}
const std::string& Sala::getOrarioFilm() const{
    return orarioFilm;
}
const std::string& Sala::getNomeFilm() const{
    return nomeFilm;
}

void Sala::occupaPosto(int _x, int _y){
    if (this->isAccettable(_x, _y)){
        if(this->isFree(_x, _y))
            this->listaPosti[_x][_y]=true;
        else if (!this->isFree(_x, _y))
            std::cout <<"Posto già occupato!" << std::endl;
    }
    else
        std::cout << "Coordinate non valide, impossibile occupare posto!" <<std::endl;
}

void Sala::stampaPostiLiberiSala() const {
    std::cout << "Lista posti liberi sala " << this->getCodice() << " :"
    << "\n   ==========   " << std::endl;
    for(int i=0; i<20; i++){
        std::cout << "Fila " << i+1 << " :  ";
        for(int j=0; j<10; j++)
            if (this->isFree(i, j))
                std::cout << j+1 <<" - " ;
        std::cout << std::endl;
    }
    std::cout << "\n   ==========   " << std::endl;
}

void Sala::liberaPosto(int _x, int _y){
    if (this->isAccettable(_x, _y))
        if(!this->isFree(_x, _y))
            this->listaPosti[_x][_y]=false;
}

void Sala::stampaGraficoPostiLiberi() const{
    if(this->almenoUnoLibero()){
        for(int i=0; i<20; i++){
            for(int j=0; j<10; j++)
                if (this->isFree(i, j))
                    std::cout << " ." ;
                else
                    std::cout << " *" ;
            std::cout << std::endl;
        }

    }
}

bool Sala::isFree(int _x, int _y) const{
    if(this->isAccettable(_x, _y)){
        if (this->listaPosti[_x][_y]==0)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool Sala::isAccettable(int _x, int _y) const{
    if(_x>=0 && _x<20 && _y>=0 && _y<10)
        return true;
    else
        return false;
}

bool Sala::almenoUnoLibero() const{
    for(int i=0; i<20; i++)
        for(int j=0; j<10; j++)
            if (this->isFree(i, j))
                return true;
    return false;
}