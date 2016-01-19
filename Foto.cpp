//
//  Foto.cpp
//  Archivio Foto
//
//  Created by Salvatore  Polito on 17/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Foto.hpp"

void Ritratto::stampa() {
    std::cout << "Nome del Ritratto: "<< this->getNomeFile() << std::endl;
    std::cout << "Data di creazione: "<< this->getDataCreazione()<< std::endl;
    std::cout << "Soggetto del ritratto: \n"  << this->getPersona();
    std::cout << "Dimensione" << std::endl;
    std::cout << "Altezza: " << this->getAltezza() << "  Larghezza: " << this->getLarghezza()<< std::endl;
}

void Ritratto::stampa() const {
    std::cout << "Nome del Ritratto: "<< this->getNomeFile() << std::endl;
    std::cout << "Data di creazione: "<< this->getDataCreazione()<< std::endl;
    std::cout << "Soggetto del ritratto \n"  << this->getPersona() ;
    std::cout << "Dimensione:" << std::endl;
    std::cout << "Altezza: " << this->getAltezza() << "  Larghezza: " << this->getLarghezza()<< std::endl;
}

void Ritratto::modifica(){
    std::string temp;
    Persona pTemp;
    int n=0;
    std::cout << "Inserire i nuovi dati:" << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "Nome del Ritratto: "; std::cin >> temp; this->setNomeFile(temp); std::cout << std::endl;
    std::cout << "\nData di creazione: "; std::cin >> temp; this->setDataCreazione(temp); std::cout << std::endl;
    std::cout << "Soggetto del ritratto: "; std::cin >>  pTemp; this->addPersona(pTemp); std::cout << std::endl;
    std::cout << "Dimensione" << std::endl;
    std::cout << "Altezza: " ; std::cin>>n; this->setAltezza(n); 
    std::cout << "  Larghezza: "; std::cin>>n; this->setLarghezza(n);

}

void Panorama::stampa(){
    std::cout << "Nome del Panorama: "<< this->getNomeFile() << std::endl;
    std::cout << "Data di creazione: "<< this->getDataCreazione()<< std::endl;
    std::cout << "Luogo: " << this->getLuogoFoto() << std::endl;
    std::cout << "Dimensione" << std::endl;
    std::cout << "Altezza: " << this->getAltezza() << "  Larghezza: " << this->getLarghezza()<< std::endl;
}

void Panorama::stampa() const {
    std::cout << "Nome del Panorama: "<< this->getNomeFile() << std::endl;
    std::cout << "Data di creazione: "<< this->getDataCreazione()<< std::endl;
    std::cout << "Luogo: " << this->getLuogoFoto() << std::endl;
    std::cout << "Dimensione" << std::endl;
    std::cout << "Altezza: " << this->getAltezza() << "  Larghezza: " << this->getLarghezza()<< std::endl;
}

void Panorama::modifica(){
    std::string temp;
    int n=0;
    std::cout << "Inserire i nuovi dati:" << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "Nome del Ritratto: "; std::cin >> temp; this->setNomeFile(temp); std::cout << std::endl;
    std::cout << "\nData di creazione: "; std::cin >> temp; this->setDataCreazione(temp); std::cout << std::endl;
    std::cout << "Luogo: "; std::cin >>  temp; this->setLuogoFoto(temp); std::cout << std::endl;
    std::cout << "Dimensione" << std::endl;
    std::cout << "Altezza: " ; std::cin>>n; this->setAltezza(n);
    std::cout << "  Larghezza: "; std::cin>>n; this->setLarghezza(n);
    
}



bool Ritratto::cercaPersona(const Persona &tosearch){
    if(this->getPersona()==(tosearch))
        return true;
    else
        return false;
}

bool Ritratto::cercaPersona(const std::string &n, const std::string &c, const std::string &dN) {
    Persona temp(n, c, dN);
    if (this->cercaPersona(temp))
        return true;
    else
        return false;
}

bool Panorama::cercaLuogo(const std::string &tosearch){
    if (this->getLuogoFoto()==tosearch)
        return true;
    else
        return false;
}