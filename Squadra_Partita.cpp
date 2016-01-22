//
//  Squadra_Partita.cpp
//  Torneo di Calcio
//
//  Created by Salvatore  Polito on 22/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Squadra_Partita.hpp"

Squadra::Squadra(){
    std::string tNome;
    std::cout << "Inserire il nome della squadra: ";
    std::cin >> tNome;
    this->setNome(tNome);
    std::cout << std::endl;
}

void Squadra::setNome(const std::string &_nome){
    if(!_nome.empty()&& this->getNome()!=_nome)
        nome=_nome;
}

const std::string& Squadra::getNome() const {
    return nome;
}


// il costruttore della classe Partita si occupa solo di settare a 0 lo stato(non giocata) e di azzerare il risultato
// una partita può essere creata solo conoscendo le due squadre
Partita::Partita() : risSq1(0), risSq2(0), status(0) {}

Partita::Partita(Squadra &_s1, Squadra &_s2) :  Partita() {
    sq1 = &_s1;
    sq2 = &_s2;
}

Squadra& Partita::getSquadra(bool _scelta ){
    if(_scelta==0)
        return *sq1;
    else
        return *sq2;
}

const Squadra& Partita::getSquadra(bool _scelta ) const {
    if(_scelta==0)
        return *sq1;
    else
        return *sq2;
}

int Partita::getRisSq1() const{
    return risSq1;
}

int Partita::getRisSq2() const{
    return risSq2;
}

void Partita::setRisultato(bool _scelta, int _valore){
    if(_scelta==0)
        risSq1=_valore;
    else if (_scelta==1)
        risSq2=_valore;
    status=1;
}

void Partita::stampaRisultato() const {
    std::cout << this->getSquadra(0).getNome() << " vs " << this->getSquadra(1).getNome() << " : "
    << this->getRisSq1() << " - " << this->getRisSq2() << std::endl;
 }

void Partita::stampaNomePartita() const {
    std::cout << this->getSquadra(0).getNome() << " vs " << this->getSquadra(1).getNome() << std::endl;
}

void Partita::setRisultato(){
    int x=0;
    std::cout << "Inserire risultato per " << this->getSquadra(0).getNome() << " :";
    std::cin >> x;
    this->setRisultato(0, x);
    
    std::cout << "Inserire risultato per " << this->getSquadra(1).getNome() << " :";
    std::cin >> x;
    this->setRisultato(1, x);
}

void Partita::cancellaRisultato(){
    if(this->isPlayed()){
        this->setRisultato(0, 0);
        this->setRisultato(1, 0);
        status=0;
    }
}

bool Partita::isPlayed() const {
    if (status==0)
        return false;
    else
        return true;
}