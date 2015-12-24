#include<iostream>
#include<string>

#include"Appuntamenti.h"
Appuntamenti::Appuntamenti() :   descrizione("---") {};
Appuntamenti::Appuntamenti(Time &t1, Time &t2, string &s) {
    this->setInizio(t1);
    this->setFine(t2);
    this->setDescrizione(s);

}
Appuntamenti::Appuntamenti(int hi, int mi, int si, int hf, int mf, int sf, std::string &des):
                                                            inizio(hi, mi, si),
                                                            fine(hf, mf, sf),
                                                            descrizione(des) {}


void Appuntamenti::print (std::ostream &os) {
    os << "Inizio: " << (this->getInizio()).getOra() << ":" << (this->getInizio()).getMinuti() << ":" << (this->getInizio()).getSecondi() << endl
       << "Fine: " << (this->getFine()).getOra() << ":" << (this->getFine()).getMinuti() << ":" << (this->getFine()).getSecondi() << endl
       << "Descrizione: " << (this->getDescrizione()) << endl;
}
//E' necessaria la ridefinzione per usare il metodo getAppuntamento della classe Agenda
void Appuntamenti::print (std::ostream &os) const {
    os << "Inizio: " << (this->getInizio()).getOra() << ":" << (this->getInizio()).getMinuti() << ":" << (this->getInizio()).getSecondi() << endl
       << "Fine: " << (this->getFine()).getOra() << ":" << (this->getFine()).getMinuti() << ":" << (this->getFine()).getSecondi() << endl
       << "Descrizione: " << (this->getDescrizione()) << endl;
}



double Appuntamenti::durata() const {
    double durata = ((((this->getFine()).getSecondi() + (((this->getFine()).getMinuti())*60) + (((this->getFine()).getOra())*60*60)) / 60)
            - (((this->getInizio()).getSecondi() + (((this->getInizio()).getMinuti())*60) + (((this->getInizio()).getOra())*60*60)) / 60));
    return durata;
    }
