//
//  Candidato.cpp
//  Elezioni Rappresentanti Studenti
//
//  Created by Salvatore  Polito on 26/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Candidato.hpp"
Candidato::Candidato()=default;

Candidato::Candidato(long m, long cc, const std::string &nC, const std::string &cC, const std::string &l) :
                                                                                        Studente(m, cc, nC, cC), lista(l)
                                                                                            {}

void Candidato::setLista(const std::string &l){
    lista=l;
}

const std::string& Candidato::getLista() const{
    return lista;
}

std::istream& operator>> (std::istream &is , Candidato &toadd){
    std::string tString;
    long tLong;
    std::cout << "Nome: ";
    is>>tString;
    toadd.setNomeStudente(tString);
    std::cout << "\nCogome: ";
    is>>tString;
    toadd.setCognomeStudente(tString);
    std::cout << "\nLista: ";
    is>>tString;
    toadd.setLista(tString);
    std::cout << "\nMatricola: ";
    is>>tLong;
    toadd.setMatricola(tLong);
    std::cout << "\nCodiceControllo: ";
    is>>tLong;
    toadd.setCodiceControllo(tLong);
    std::cout << std::endl;
    
    return is;
}

std::ostream& operator<< (std::ostream &os, Candidato &toprint){
    os << toprint.getMatricola() << "  -  " << toprint.getNomeStudente() << "  -  " << toprint.getCognomeStudente()
        << "  -  " << toprint.getLista() ;
    return os;
}