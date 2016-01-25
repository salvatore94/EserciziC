//
//  Cinema.cpp
//  Biglietteria Cinema
//
//  Created by Salvatore  Polito on 25/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Cinema.hpp"
Cinema::Cinema() {
    listaSala[0].setCodice('A');
    listaSala[1].setCodice('B');
    listaSala[1].setCodice('C');
    listaSala[3].setCodice('D');
}

void Cinema::stampaPostiLiberiTutteLeSale() {
    for(int i=0; i<4; i++)
        this->listaSala[i].stampaPostiLiberiSala();
}

void Cinema::emissioneBiglietto() {
    std::cout << "Inserire codice sala: ";
    char tempChar;
    std::cin >> tempChar;
    int pos=this->cercaSala(tempChar);
    if(pos==-1)
        std::cout << "Codice non trovato!" << std::endl;
    else {
        this->listaSala[pos].stampaGraficoPostiLiberi();
        std::cout << "Inserire fila e poltorna: " ;
        int x, y;
        std::cin >> x >> y;
        if(this->listaSala[pos].isFree(x, y)){
            std::cout << "\nPosto registrato! " << std::endl;
            this->listaSala[pos].occupaPosto(x, y);
            Biglietto temp(tempChar, x, y, this->listaSala[pos].getOrarioFilm(), this->listaSala[pos].getNomeFilm());
            this->aggiungiBiglietto(temp);
            temp.stampaBiglietto();
        }
            
    }
}

void Cinema::resettaSala(){
    std::cout << "Inserire codice sala: ";
    char tempC;
    std::cin >> tempC;
    int pos=this->cercaSala(tempC);
    std::cout << std::endl;
    if(pos==-1)
        std::cout << "Codice non trovato!" << std::endl;
    else {
        std::cout << "Dati correnti della sala:"
        << "\nTitolo:" << this->listaSala[pos].getNomeFilm()
        << "\nOrario film:" << this->listaSala[pos].getOrarioFilm() << std::endl;
        
        this->listaSala[pos].stampaGraficoPostiLiberi();
        std::string tempS;
        std::cout << "Nuovo titolo: ";
        std::getline(std::cin, tempS);
        this->listaSala[pos].setNomeFilm(tempS);
        std::cout << "\nNuovo orario: ";
        std::getline(std::cin, tempS);
        this->listaSala[pos].setOrarioFilm(tempS);
        std::cout << std::endl;
        this->listaSala[pos].liberaTutto();
    }
}

void Cinema::aggiungiBiglietto( Biglietto &toadd){
    listaBiglietti.push_back(&toadd);
}

Biglietto& Cinema::getBiglietto(int _pos){
    if (_pos <= listaBiglietti.size())
        return *listaBiglietti[_pos];
    return *listaBiglietti[0];
}

int Cinema::cercaSala (char _codice){
    for (int i=0; i<4; i++)
        if(this->listaSala[i].getCodice()==_codice)
            return i;
    
    return -1;
}