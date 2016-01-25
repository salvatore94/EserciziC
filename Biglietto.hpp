//
//  Biglietto.hpp
//  Biglietteria Cinema
//
//  Created by Salvatore  Polito on 25/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Biglietto_hpp
#define Biglietto_hpp

#include <iostream>
#include <string>

class Biglietto {
    char codiceSala;
    int fila, poltrona;
    
    std::string orarioInizio;
    std::string titoloFilm;
    
public:
    Biglietto();
    Biglietto (char, int, int, const std::string&, const std::string&);
    
    void setCodiceSala(char);
    void scegliPosto(int, int);
    void scegliFila(int);
    void scegliPoltrona(int);
    void setOrarioInizio(const std::string&);
    void setTitoloFilm (const std::string&);
    
    
    char getCodiceSala() const;
    int getFila() const;
    int getPoltrona() const;
    const std::string& getOrarioInizio() const;
    const std::string& getTitoloFilm () const;
    
    void stampaBiglietto() const;
};

#endif /* Biglietto_hpp */
