//
//  ApplicazioneInstallata.cpp
//  Gestione Applicazioni (1)
//
//  Created by Salvatore  Polito on 02/02/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "ApplicazioneInstallata.hpp"
ApplicazioneInstallata::ApplicazioneInstallata( Applicazione &a1) {
    this->setId(a1.getId());
    this->setVersione(a1.getVersione());
    this->setNomeApplicazione(a1.getNomeApplicazione());
    this->setDescrizioneApplicazione(a1.getDescrizioneApplicazione());
    
    this->setMemoriaOccupata(100 + (rand() % 2000));
}

void ApplicazioneInstallata::setMemoriaOccupata(long n) {
    memoriaOccupata=n;
}

long ApplicazioneInstallata::getMemoriaOccupata() {
    return memoriaOccupata;
}

std::ostream& operator<< (std::ostream &os,  ApplicazioneInstallata &toprint){
    os << toprint.getId() <<" - " <<toprint.getNomeApplicazione() << " - " << toprint.getVersione()<< " - " << toprint.getMemoriaOccupata() << std::endl;
    
    return os;
}

std::istream& operator>> (std::istream &in, ApplicazioneInstallata &a) {
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
    a.setMemoriaOccupata(100 + (rand() % 2000));
    
    return in;
}