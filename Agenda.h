#ifndef AGENDA_H
#define AGENDA_H

#include"Appuntamenti.h"
#include<vector>

class Agenda {
    std::vector<Appuntamenti> dati;

public:
    Agenda() {Appuntamenti test; dati.push_back(test); std::cout << "Cotruttore di default Agenda"<< std:: endl;};
    Agenda (Appuntamenti&);
    //Agenda (int hi, int mi, int si, int hf, int mf, int sf, std::string &des) : dati[0](hi,mi,si,hf,mf,sf,des)
    //                                                                            {};

    void aggiungi (const Appuntamenti&);
    void cerca (const Time&) const;
    void cerca (const string&) const;

     Appuntamenti& getAppuntamento (int pos) { return dati[pos];}
};
#endif
