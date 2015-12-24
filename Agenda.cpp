#include<iostream>

Agenda::Agenda (const Appuntamento &a1) {
    dati.push_back(a1);
}

void Agenda::aggiungi (const Appuntamenti &nuovo) {
    dati.push_back(nuovo);
    std::cout << "Metodo aggiungi invocato" << std::endl;
}

void Appuntamenti::cerca (const string &des) const {
    for(int i=0; i<=dati.getsize(); ++i)
        if(this->getAppuntamento(i).getDescrizione()==des)
            this->getAppuntamento(i).print(std::cout);
}
void Appuntamenti::cerca (const Time &ref) const {
    for(int i=0, i<=dati.size(); ++i)
        if(this->getAppunamento(i).getInizio()==ref)
            this->getAppunamento(i).print(std::cout);
}
