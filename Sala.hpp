//
//  Sala.hpp
//  Biglietteria Cinema
//
//  Created by Salvatore  Polito on 25/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Sala_hpp
#define Sala_hpp

#include <iostream>
#include <string>

class Sala {
    char codice;
    bool listaPosti[20][10];
    
    std::string orarioFilm;
    std::string nomeFilm;
    
    bool isAccettable(int, int) const;
    bool almenoUnoLibero() const;
public:
    Sala();
    
    void setCodice (char);
    void setOrarioFilm(const std::string&);
    void setNomeFilm (const std::string&);
    
   char getCodice() const;
    const std::string& getOrarioFilm() const;
    const std::string& getNomeFilm() const;

    void occupaPosto(int, int);
    void liberaPosto(int, int);
    bool isFree(int, int) const;
    
    void liberaTutto();
    
    void stampaPostiLiberiSala() const;
    void stampaGraficoPostiLiberi() const;
};

#endif /* Sala_hpp */
