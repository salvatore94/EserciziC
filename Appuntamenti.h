#ifndef APPUNTAMENTI_H
#define APPUNTAMENTI_H

#include<iostream>
#include<string>

#include"Time.cpp"

class Appuntamenti {
    Time inizio, fine;
    std::string descrizione;

    void setInizio (Time &t1) { this->inizio = t1; }
    void setFine (Time &t2) { this->fine = t2; }
    void setDescrizione (string &s) {this->descrizione = s; }

public:
    Appuntamenti();
    Appuntamenti(Time&, Time&, string&);

    const Time& getInizio () const { return this->inizio; }
    const Time& getFine () const { return this->fine; }
    const std::string& getDescrizione () const { return this->descrizione; }

    void print(std::ostream&);
    double durata() const;
};

#endif
