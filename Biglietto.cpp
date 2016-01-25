//
//  Biglietto.cpp
//  Biglietteria Cinema
//
//  Created by Salvatore  Polito on 25/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Biglietto.hpp"
//inizialmente il biglietto ha codice di sala A e posto 0,0
Biglietto::Biglietto(){
    this->setCodiceSala('A');
    this->scegliPosto(0, 0);
}

Biglietto::Biglietto (char _codice, int _x, int _y, const std::string &orario, const std::string &nome){
    this->setCodiceSala(_codice);
    this->scegliPosto(_x, _y);
    this->setOrarioInizio(orario);
    this->setTitoloFilm(nome);
}

void Biglietto::setCodiceSala(char _s){
    if(_s == 'A' || _s == 'B' || _s == 'C' || _s == 'D')
        codiceSala=_s;
}
void Biglietto::scegliPosto(int x, int y){
    this->scegliFila(x);
    this->scegliPoltrona(y);
}
void Biglietto::scegliFila(int _fila){
    if(_fila>=0 && _fila<20)
        fila=_fila;
}
void Biglietto::scegliPoltrona(int _poltrona) {
    if (_poltrona>=0 && _poltrona<10)
        poltrona=_poltrona;
}
void Biglietto::setOrarioInizio(const std::string &t){
    orarioInizio=t;
}
void Biglietto::setTitoloFilm (const std::string &t){
    titoloFilm=t;
}


void Biglietto::stampaBiglietto() const{
    std::cout << "Dettagli biglietto"
            <<"\n=================\n"
            << "Codice Sala: " << this->getCodiceSala()
            <<"\nFila: " << this->getFila()+1 << " Poltrona: " << this->getPoltrona()+1
            <<"\nNome Film: " << this->getTitoloFilm()
            <<"\nOrario d'Inizio: " << this->getOrarioInizio()
    <<"\n================" << std::endl;
}

char Biglietto::getCodiceSala() const{
    return codiceSala;
}
int Biglietto::getFila() const{
    return fila;
}
int Biglietto::getPoltrona() const{
    return poltrona;
}
const std::string& Biglietto::getOrarioInizio() const{
    return orarioInizio;
}
const std::string& Biglietto::getTitoloFilm () const{
    return titoloFilm;
}