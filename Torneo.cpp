//
//  Torneo.cpp
//  Torneo di Calcio
//
//  Created by Salvatore  Polito on 22/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Torneo.hpp"
Torneo::Torneo() {
    for(int i=0; i<12; i++){
        std::cout << i+1 <<". squadra:" << std::endl;
        Squadra temp;
        this->addSquadraTorneo(i, temp);
    }
    
    //Girone 1
    Partita p1(this->getSquadra(0), this->getSquadra(1));
    Partita p2 (this->getSquadra(1), this->getSquadra(2));
    Partita p3 (this->getSquadra(0), this->getSquadra(2));
    Girone g1(p1,p2,p3);
    this->addGironeTorneo(0, g1);

    //Girone 2
    Partita p4(this->getSquadra(3), this->getSquadra(4));
    Partita p5 (this->getSquadra(4), this->getSquadra(5));
    Partita p6 (this->getSquadra(3), this->getSquadra(5));
    Girone g2(p4,p5,p5);
    this->addGironeTorneo(1, g2);
    
    //Girone 3
    Partita p7(this->getSquadra(6), this->getSquadra(7));
    Partita p8 (this->getSquadra(7), this->getSquadra(8));
    Partita p9 (this->getSquadra(6), this->getSquadra(8));
    Girone g3(p7,p8,p9);
    this->addGironeTorneo(2, g3);
    
    //Girone 4
    Partita p10(this->getSquadra(9), this->getSquadra(10));
    Partita p11 (this->getSquadra(10), this->getSquadra(11));
    Partita p12 (this->getSquadra(9), this->getSquadra(11));
    Girone g4(p10,p11,p12);
    this->addGironeTorneo(3, g4);
}

Girone& Torneo::getGirone(int _pos){
    if(_pos>=0 && _pos<4)
        return *listaGironi[_pos];
    else
        return *listaGironi[_pos];
}

void Torneo::addSquadraTorneo(int _pos, Squadra &toadd) {
    if(_pos>=0 && _pos<12)
        listaSquadre[_pos]=&toadd;
}

void Torneo::addGironeTorneo(int _pos, Girone &toadd){
    if(_pos>=0 && _pos<4)
        listaGironi[_pos]=&toadd;
}

Squadra& Torneo::getSquadra(int _pos) {
    if(_pos>=0 && _pos<12)
        return *listaSquadre[_pos];
    else
        return *listaSquadre[0];
}

void Torneo::setRisultato(){
    char scelta;
    std::cout << "Inserire codice girone (A-D): ";
    std::cin >> scelta; std::cout << std::endl;
    
    if (scelta=='A' || scelta=='a'){
        for(int i=0; i<3; i++)
            if(!this->getGirone(0).getPartita(i).isPlayed()){
                char c;
                this->getGirone(0).getPartita(i).stampaNomePartita();
                std::cout << "Premere 'Y' per assegnare un risultato.." << std::endl;
                if(c=='y' || c=='Y')
                    this->getGirone(0).getPartita(i).setRisultato();
            }
    }
    else if (scelta=='B' || scelta=='b') {
        for(int i=0; i<3; i++)
            if(!this->getGirone(1).getPartita(i).isPlayed()){
                char c;
                this->getGirone(1).getPartita(i).stampaNomePartita();
                std::cout << "Premere 'Y' per assegnare un risultato.." << std::endl;
                if(c=='y' || c=='Y')
                    this->getGirone(1).getPartita(i).setRisultato();
            }
    }
    else if (scelta=='C' || scelta=='c'){
        for(int i=0; i<3; i++)
            if(!this->getGirone(2).getPartita(i).isPlayed()){
                char c;
                this->getGirone(2).getPartita(i).stampaNomePartita();
                std::cout << "Premere 'Y' per assegnare un risultato.." << std::endl;
                if(c=='y' || c=='Y')
                    this->getGirone(2).getPartita(i).setRisultato();
            }
    }
    else if (scelta=='D' || scelta=='d'){
        for(int i=0; i<3; i++)
            if(!this->getGirone(3).getPartita(i).isPlayed()){
                char c;
                this->getGirone(3).getPartita(i).stampaNomePartita();
                std::cout << "Premere 'Y' per assegnare un risultato.." << std::endl;
                if(c=='y' || c=='Y')
                    this->getGirone(3).getPartita(i).setRisultato();
            }
    }
    else{
        std::cout << "Codice non valido!" << std::endl;
        this->setRisultato();
        }
    
}

void Torneo::stampaStatoGirone(){
    char scelta;
    std::cout << "Inserire codice girone (A-D): ";
    std::cin >> scelta; std::cout << std::endl;
    
    if (scelta=='A' || scelta=='a') {
        this->getGirone(0).stampaStatoGirone();
    }
    else if (scelta=='B' || scelta=='b'){
        this->getGirone(1).stampaStatoGirone();
    }
    else if (scelta=='C' || scelta=='c'){
        this->getGirone(2).stampaStatoGirone();
    }
    else if (scelta=='D' || scelta=='d'){
        this->getGirone(3).stampaStatoGirone();
    }
    else{
        std::cout << "Codice non valido!" << std::endl;
        this->stampaStatoGirone();
        }
}

void Torneo::stampaTuttiIGironi(){
    for(int i=0; i<4; i++)
        this->getGirone(i).stampaStatoGirone();
}

void Torneo::cancellaTuttiIRisultati(){
    for(int i=0; i<4; i++)
        this->getGirone(i).cancellaRisultatiGirone();
}




