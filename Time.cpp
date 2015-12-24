#include"Time.h"



void Time::setOra(int h) {
    if(h>0 && h<24)
        this->ora=h;
    else
        this->ora=0;
}

void Time::setMinuti(int m) {
    if(m>0 && m<60)
        this->minuti=m;
    else
        this->minuti=0;
}

void Time::setSecondi(int s) {
    if(s>0 && s<60)
        this->secondi=s;
    else
        this->secondi=0;
}
/*
double Time::timeTotal() const {
    return (((this->getSecondi)+((this->getMinuti)*60)+(((this->getOra)*60)*60)) / 60);
}
*/
