//
//  Girone.cpp
//  Torneo di Calcio
//
//  Created by Salvatore  Polito on 22/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Girone.hpp"

Girone::Girone() {
    counter=0;
}

Girone::Girone(Partita &p1, Partita &p2, Partita &p3) {
    this->addPartitaGirone(0, p1);
    this->addPartitaGirone(1, p2);
    this->addPartitaGirone(2, p3);
    counter=3;
}

Partita& Girone::getPartita(int _pos){
    if(_pos>=0 && _pos<3 && !isValid())
        return partitaGirone[_pos];
    else                                //si suppone che la prima partita sia sempre presente
        return partitaGirone[0];
}

void Girone::addPartitaGirone(int _pos, Partita &p){
    if(_pos>=0 && _pos<3 && !isValid()){   //aggiungo le partite solo se il girone non è completo
        partitaGirone[_pos]=p;
        counter++;
    }
}

void Girone::stampaStatoGirone(){
    std::cout << "Partite Giocate" << std::endl;
    for (int i=0; i<3; i++)
        if(this->getPartita(i).isPlayed())
            this->getPartita(i).stampaRisultato();
    this->stampaPartiteDaGiocare();
}

void Girone::stampaPartiteDaGiocare(){
    std::cout << "Partite da giocare" << std::endl;
    for (int i=0; i<3; i++)
        if(!this->getPartita(i).isPlayed())
            this->getPartita(i).stampaNomePartita();
}

void Girone::cancellaRisultatiGirone(){
    for(int i=0; i<3; i++)
        this->getPartita(i).cancellaRisultato();
}

bool Girone::isValid() {
    if (counter==3)
        return true;
    else
        return false;
}