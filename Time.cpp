#include"Time.h"

Time::Time (const Time &tocopy) {
    this->set(tocopy.getOra(), tocopy.getMinuti(), tocopy.getSecondi());
}

bool Time::operator== (const Time &t2) {
     if ((this->getOra())==t2.getOra() && (this->getMinuti())==t2.getMinuti() && (this->getSecondi())==t2.getSecondi())
        return true;
    return false;
}

bool Time::operator== (const Time &t2) const {
     if ((this->getOra())==t2.getOra() && (this->getMinuti())==t2.getMinuti() && (this->getSecondi())==t2.getSecondi())
        return true;
    return false;
}
bool Time::operator< (const Time &t2) {
        if (ora>t2.getOra())
                return true;
        else if (ora==t2.getOra()&& minuti>t2.getMinuti())
                return true;
        else if (ora==t2.getOra()&& minuti==t2.getMinuti()&& secondi>t2.getSecondi())
                return true;
        else
            return false;
}

bool Time::operator< (const Time &t2) const {
        if (ora>t2.getOra())
                return true;
        else if (ora==t2.getOra()&& minuti>t2.getMinuti())
                return true;
        else if (ora==t2.getOra()&& minuti==t2.getMinuti()&& secondi>t2.getSecondi())
                return true;
        else
            return false;
}

Time& Time::operator+ (const Time &t2) {
    Time temp;
    temp.setOra(ora+t2.getOra());
    temp.setMinuti(minuti+t2.getMinuti());
    temp.setSecondi(secondi+t2.getSecondi());

    return temp;
}

Time& Time::operator+ (const Time &t2) const {
    Time temp;
    temp.setOra(ora+t2.getOra());
    temp.setMinuti(minuti+t2.getMinuti());
    temp.setSecondi(secondi+t2.getSecondi());

    return temp;
}

Time& Time::operator- (const Time &t2) {
    Time temp;
    temp.setOra((t2.getOra())-ora);
    temp.setMinuti((t2.getMinuti())-minuti);
    temp.setSecondi((t2.getSecondi())-secondi);

    return temp;
}

Time& Time::operator- (const Time &t2) const {
    Time temp;
    temp.setOra((t2.getOra())-ora);
    temp.setMinuti((t2.getMinuti())-minuti);
    temp.setSecondi((t2.getSecondi())-secondi);

    return temp;
}

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
