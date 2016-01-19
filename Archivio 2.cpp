//
//  Archivio.cpp
//  Archivio Foto
//
//  Created by Salvatore  Polito on 18/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Archivio.hpp"
Archivio::Archivio(const std::string &nome) : nomeArchivio(nome), count(0), dataPtr(nullptr) {}

Archivio::~Archivio() {
    delete[] dataPtr;
}
void Archivio::setNomeArchivio(const std::string &n){
    nomeArchivio=n;
}

const std::string& Archivio::getNomeArchivio () const {
    return nomeArchivio;
}

const std::string& Archivio::getNomeArchivio () {
    return nomeArchivio;
}


int Archivio::getSize() const {
    return count-1;
}

int Archivio::cercaFoto(const std::string &nome) const {
    for (int i=0; i!= this->getSize(); ++i)
        if (this->getFoto(i)->getNomeFile() == nome)
            return i;
    return -1;
}

void Archivio::modificaFoto(){
    std::string nome;
    std::cout << "Inserire il nome della foto da modificare: ",
    std::cin >> nome;
    
    int pos = this->cercaFoto(nome);
    if (pos== -1)
        std::cout << "Foto non trovata!" << std::endl;
    else {
        this->getFoto(pos)->stampa();
        std::cout << " ----- MODIFICA ----- " << std::endl;
        this->getFoto(pos)->modifica();
    }
}


Foto* Archivio::getFoto(int _pos) const {
    if(_pos>=0 && _pos<=count)
        return dataPtr[_pos];
    else
        return dataPtr[0];  //per evitare problemi restituisco il primo elemento
}

Foto* Archivio::getFoto(int _pos) {
    if(_pos>=0 && _pos<=count)
        return dataPtr[_pos];
    else
        return dataPtr[0];  //per evitare problemi restituisco il primo elemento
}

void Archivio::addFoto (Foto *toadd){
    if (count > 0){
        Foto** temp= new Foto* [count];
    
        for (int i=0; i<=this->getSize(); i++)
        temp[i]=dataPtr[i];
        temp[count]=toadd;
        ++count;
        delete [] dataPtr;
        dataPtr=temp;
    }
    if (count ==0){
        dataPtr=new Foto*[1];
        dataPtr[0]=toadd;
        count++;
    }
    
}

void Archivio::cercaPerLuogo() {
    std::cout << "Inserire luogo da ricercare: ";
    std::string temp;
    std::cin >> temp;
    std::cout << std::endl;
    
    for (int i=0; i<=this->getSize(); i++)
        if (dataPtr[i]->cercaLuogo(temp))
            this->getFoto(i)->stampa();
}

void Archivio::cercaPerSoggetto() {
    std::string temp;
    Persona pTemp;
    std::cout << "Inserire dati da ricercare " <<std::endl;
    std::cin >> pTemp;
    std::cout << std::endl;
    
    for (int i=0; i<=this->getSize(); i++)
        if(this->getFoto(i)->cercaPersona(pTemp))
            this->getFoto(i)->stampa();
}

void Archivio::printAll() const {
    std::cout << "Nome Archivio: " << this->getNomeArchivio() << std::endl;
    std::cout << "Elenco contenuti"<< std::endl;
    std::cout << "=========================" << std::endl;
    for (int i=0; i<=this->getSize(); i++)
        this->getFoto(i)->stampa();
}
