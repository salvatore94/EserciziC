//
//  Persona.cpp
//  Archivio Foto
//
//  Created by Salvatore  Polito on 18/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Persona.hpp"

void Persona::setNome(const std::string &n){
    nome=n;
}
void Persona::setCognome (const std::string &c){
    cognome=c;
}
void Persona::setDataNascita (const std::string &dN){
    dataNascita=dN;
}


bool Persona::operator==(const Persona &tosearch) const {
    if (this->getNome()==tosearch.getNome() && this->getCognome()==tosearch.getCognome() && this->getDataNascita()==tosearch.getDataNascita())
        return true;
    else
        return false;
}

std::ostream& operator<< (std::ostream &os, const Persona &toprint){
    os<< "Nome: " << toprint.getNome() << "  Cognome: " << toprint.getCognome() << "  Data di nascita: " <<toprint.getDataNascita() << std::endl;
    return os;
}

std::istream& operator>> (std::istream &in, Persona &newP){
    std::string temp;
    std::cout << "Nome: ";
    in >> temp;
    newP.setNome(temp);
    std::cout << "\nCognome: ";
    in>> temp;
    newP.setCognome(temp);
    std::cout << "\nData di Nascita: ";
    in>>temp;
    newP.setDataNascita(temp);
    std::cout<< std::endl;
    
    return in;
}

