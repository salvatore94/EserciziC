#ifndef APPUNTAMENTI_H
#define APPUNTAMENTI_H

#include<iostream>
#include<string>

#include"Time.cpp"

class Appuntamenti {
    Time inizio, fine;
    std::string descrizione;

    void setInizio (Time &t1) { inizio = t1; }
    void setFine (Time &t2) { fine = t2; }
    void setDescrizione (string &s) { descrizione = s; }

public:
    Appuntamenti();
    Appuntamenti(Time&, Time&, string&) ;
    Appuntamenti(int hi, int mi, int si, int hf, int mf, int sf, std::string &des);

    const Time& getInizio () const { return this->inizio; }
    const Time& getFine () const { return this->fine; }
    const std::string& getDescrizione () const { return this->descrizione; }

    void print(std::ostream&);
    double durata() const;
};

#endif
