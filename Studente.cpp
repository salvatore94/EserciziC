//
//  Studente.cpp
//  Elezioni Rappresentanti Studenti
//
//  Created by Salvatore  Polito on 26/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Studente.hpp"
Studente::Studente()=default;

Studente::Studente(long m, long cc, const std::string &nS, const std::string &cS) :
                                                                    matricola(m), codiceControllo(cc), nome(nS), cognome(cS)
                                                                        {}

void Studente::setMatricola(long m){
    matricola=m;
}
void Studente::setCodiceControllo(long cc){
    codiceControllo=cc;
}
void Studente::setNomeStudente(const std::string &nS){
    nome=nS;
}
void Studente::setCognomeStudente(const std::string &cS){
    cognome=cS;
}

long Studente::getMatricola() const {
    return matricola;
}
long Studente::getCodiceControllo() const {
    return codiceControllo;
}
const std::string& Studente::getNomeStudente() const {
    return nome;
}
const std::string& Studente::getCognomeStudente() const {
    return cognome;
}

std::istream& operator>> (std::istream &is , Studente &toadd){
    std::string tString;
    long tLong;
    std::cout << "Nome: ";
    is>>tString;
    toadd.setNomeStudente(tString);
    std::cout << "\nCogome: ";
    is>>tString;
    toadd.setCognomeStudente(tString);
    std::cout << "\nMatricola: ";
    is>>tLong;
    toadd.setMatricola(tLong);
    std::cout << "\nCodiceControllo: ";
    is>>tLong;
    toadd.setCodiceControllo(tLong);
    std::cout << std::endl;
    
    return is;
}

std::ostream& operator<< (std::ostream &os, Studente &toprint){
    os << toprint.getMatricola() << "  -  " << toprint.getNomeStudente() << "  -  " << toprint.getCognomeStudente() ;
    return os;
}


bool Studente::isValid( long _cc){
    if(codiceControllo==_cc)
        return true;
    else
        return false;
}