#include<iostream>
#include"Agenda.h"
Agenda::Agenda() {
    Appuntamenti test;
    dati.push_back(test);
    std::cout << "Cotruttore di default Agenda"<< std:: endl;};

Agenda::Agenda (Appuntamenti &a1) {
    dati.push_back(a1);
    std::cout <<"Costruttore parametrizzato Agenda"<<std::endl;
}

void Agenda::aggiungi (const Appuntamenti &nuovo) {
    dati.push_back(nuovo);
    std::cout << "Metodo aggiungi invocato" << std::endl;
}

void Agenda::cerca (const string &des) const {
    for(int i=0; i<=dati.getsize(); ++i)
        if(this->getAppuntamento(i).getDescrizione()==des)
            this->getAppuntamento(i).print(std::cout);
}
void Appuntamenti::cerca (const Time &ref) const {
    for(int i=0, i<=dati.size(); ++i)
        if(this->getAppunamento(i).getInizio()==ref)
            this->getAppunamento(i).print(std::cout);
}
