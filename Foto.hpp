//
//  Foto.hpp
//  Archivio Foto
//
//  Created by Salvatore  Polito on 17/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Foto_hpp
#define Foto_hpp
#include "Persona.hpp"
#include <iostream>
#include <string>

class Foto {
    std::string nomeFile, dataCreazione;
    int altezza,larghezza; //servono per memorizzare la risoluzione
public:
    Foto();
    Foto(const std::string &_nF, const std::string &_dC, int _h, int _w): nomeFile(_nF), dataCreazione(_dC), altezza(_h), larghezza(_w) {}
    
    void virtual stampa ()=0;
    void virtual stampa () const =0;
    void virtual modifica ()=0;
    
    bool virtual cercaLuogo (const std::string&)=0;
    bool virtual cercaPersona (const Persona&)=0;
    
    void setNomeFile(const std::string &_nF) {nomeFile=_nF;}
    void setDataCreazione (const std::string &_dC) {dataCreazione=_dC;}
    void setAltezza (int _h) {altezza=_h;}
    void setLarghezza (int _w) {larghezza=_w;}
    
    const std::string& getNomeFile () const {return nomeFile;}
    const std::string& getDataCreazione () const {return dataCreazione;}
    int getAltezza () const {return altezza;}
    int getLarghezza() const {return larghezza;}
};

class Ritratto : public Foto {
    Persona soggetto;
public:
    Ritratto() = default; //per ora
    Ritratto(const std::string &_nF, const std::string &_dC, int _h, int _w, const Persona &_p): Foto(_nF, _dC, _h, _w), soggetto(_p) {}
    
    void addPersona (const Persona &p) {soggetto=p;}
    const Persona& getPersona() const {return soggetto;}
    
    void stampa();
    void stampa() const;
    void modifica();
    
    bool cercaLuogo (const std::string &l) {return false;}
    bool cercaPersona (const Persona&);
    bool cercaPersona (const std::string&, const std::string&, const std::string&);
};

class Panorama : public Foto {
    std::string luogoFoto;
public:
    Panorama() = default; //per ora
    Panorama (const std::string &_nF, const std::string &_dC, int _h, int _w, const std::string &_lF): Foto(_nF, _dC, _h, _w), luogoFoto(_lF) {}
    
    void setLuogoFoto(const std::string &_lF) {luogoFoto=_lF;}
    const std::string& getLuogoFoto() const {return luogoFoto;}
    
    void stampa();
    void stampa() const;
    void modifica();
    
    bool cercaPersona (const Persona &p) {return false;}
    bool cercaLuogo (const std::string&);
};


#endif /* Foto_hpp */
