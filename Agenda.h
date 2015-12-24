#ifndef AGENDA_H
#define AGENDA_H

#include"Appuntamenti.h"


class Agenda {
    std::vector<Appuntamenti> dati;
    static int count=0;

public:
    Agenda() ;
    Agenda (Appuntamenti&);
    //Agenda (int hi, int mi, int si, int hf, int mf, int sf, std::string &des) : dati[0](hi,mi,si,hf,mf,sf,des)
    //
    ~Agenda();

    void aggiungi (Appuntamenti&);
    void cerca (const Time&) const;
    void cerca (const string&) const;
    int dimensione() {return dati.size();}
    const int dimensione() const {return dati.size();}

    int getCount () { return count;}
    Appuntamenti& getAppuntamento (int pos) { return dati[pos];}
    const Appuntamenti& getAppuntamento (int pos) const { return dati[pos];}
};
#endif
