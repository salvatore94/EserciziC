#include<iostream>
#include<vector>
#include"Agenda.h"
Agenda::Agenda() {
    Appuntamenti test;
    dati.push_back(test);
    std::cout << "Cotruttore di default Agenda"<< std:: endl;};

Agenda::Agenda (Appuntamenti &a1) {
    dati.push_back(a1);
    std::cout <<"Costruttore parametrizzato Agenda"<<std::endl;
}

void Agenda::aggiungi (Appuntamenti &nuovo) {
    dati.push_back(nuovo);
    std::cout << "Metodo aggiungi invocato" << std::endl;
}

void Agenda::cerca (const string &des) const {
    for(int i=0; i!=this->dimensione(); ++i)
        if(this->getAppuntamento(i).getDescrizione()==des)
            this->getAppuntamento(i).print(std::cout);
}
void Agenda::cerca (const Time &ref) const {
    for(int i=0; i!=this->dimensione(); ++i)
        if(this->getAppuntamento(i).getInizio()==ref)
            this->getAppuntamento(i).print(std::cout);
}
