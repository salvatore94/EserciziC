//
//  Applicazione.cpp
//  Gestione Applicazioni (1)
//
//  Created by Salvatore  Polito on 02/02/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Applicazione.hpp"
Applicazione::Applicazione() {
    long x=0;
    int v=0;
    std::string temp;
    std::cout << "Inserire nome: ";
    std::cin >>temp;
    this->setNomeApplicazione(temp);
    std::cout << "\nInserire ID: ";
    std::cin >> x;
    this->setId(x);
    std::cout << "\nInserire versione: ";
    std::cin >> v;
    this->setVersione(v);
    std::cout << "\nInserire descrizione: ";
    std::cin >>temp;
    this->setDescrizioneApplicazione(temp);
    std::cout << std::endl;
}

void Applicazione::setId(long n) {
    id=n;
}

void Applicazione::setVersione(int v) {
    versione =v;
}

void Applicazione::setNomeApplicazione(const std::string &n) {
    nomeApplicazione=n;
}

void Applicazione::setDescrizioneApplicazione(const std::string &d) {
    descrizioneApplicazione=d;
}

long Applicazione::getId() {
    return id;
}

int Applicazione::getVersione() {
    return versione;
}

const std::string& Applicazione::getNomeApplicazione() {
    return nomeApplicazione;
}

const std::string& Applicazione::getDescrizioneApplicazione() {
    return descrizioneApplicazione;
}

std::ostream& operator<< (std::ostream &os,  Applicazione &toprint){
    os << toprint.getId() <<" - " <<toprint.getNomeApplicazione() << " - " << toprint.getVersione()<< std::endl;
    
    return os;
}

std::istream& operator>> (std::istream &in, Applicazione &a) {
    long x=0;
    int v=0;
    std::string temp;
    std::cout << "Inserire nome: ";
    in >>temp;
    a.setNomeApplicazione(temp);
    std::cout << "\nInserire ID: ";
    in >> x;
    a.setId(x);
    std::cout << "\nInserire versione: ";
    in >> v;
    a.setVersione(v);
    std::cout << "\nInserire descrizione: ";
    in >>temp;
    a.setDescrizioneApplicazione(temp);
    std::cout << std::endl;
    
    
    return in;
}