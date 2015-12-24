#ifndef TIME_H
#define TIME_H

class Time {
    int ora, minuti, secondi;
    void setOra(int);
    void setMinuti(int);
    void setSecondi(int);

public:
    Time(): Time(0,0,0) {};
    Time(int hh, int mm, int ss) { this->set(hh,mm,ss); }

    Time& set (int h, int m , int s) { this->setOra(h); this->setMinuti(m); this->setSecondi(s); return *this; }
    const int getOra() const {return this->ora;}
    const int getMinuti() const {return this->minuti;}
    const int getSecondi() const {return this->secondi;}

    //restituisce l'orario in minuti
    //double timeTotal() const;
};

#endif
