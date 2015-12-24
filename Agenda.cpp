#include<iostream>
#include<vector>
#include"Agenda.h"
Agenda::Agenda() {
    Appuntamenti test;
    dati.push_back(test);
    std::cout << "Cotruttore di default Agenda"<< std:: endl;

    ++count;
};

Agenda::Agenda (Appuntamenti &a1) {
    dati.push_back(a1);
    std::cout <<"Costruttore parametrizzato Agenda"<<std::endl;

    ++count;
}

Agenda::~Agenda() {
    --count;
    std::cout <<"Distruttore invocato" << std::endl;
}

void Agenda::aggiungi (Appuntamenti &nuovo) {
    dati.push_back(nuovo);
    std::cout << "Metodo aggiungi invocato" << std::endl;

    ++count;
}

void Agenda::cerca (const string &des) const {
    std::cout << "Metodo cerca tramite stringa invocato"<< std::endl;
    for(int i=0; i!=this->dimensione(); ++i)
        if(this->getAppuntamento(i).getDescrizione()==des)
            this->getAppuntamento(i).print(std::cout);
}

void Agenda::cerca (const Time &ref) const {
    std::cout << "Metodo cerca tramite Time& invocato"<< std::endl;
    for(int i=0; i!=this->dimensione(); ++i)
        if((this->getAppuntamento(i).getInizio()==ref) || (this->getAppuntamento(i).getFine()==ref))
            this->getAppuntamento(i).print(std::cout);
}
