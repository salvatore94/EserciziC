#ifndef AGENDA_H
#define AGENDA_H

#include"Appuntamenti.h"
#include"Agenda.cpp"
class Agenda {
    vector<Appuntamenti> dati;

public:
    Agenda();
    Agenda (const Appuntamento&);
    Agenda (int hi, int mi, int si, int hf, int mf, int sf, std::string &des) : Appuntamenti a1(hi,mi,si,hf,mf,sf,des),
                                                                                Agenda(&a1), {};

    void aggiungi (const Appuntamenti&);
    void cerca (const Time&) const;
    void cerca (const string&) const;

    const Appuntamento& getAppuntamento (int pos) { return dati[pos];}
};
#endif
