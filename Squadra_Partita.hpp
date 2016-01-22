//
//  Squadra_Partita.hpp
//  Torneo di Calcio
//
//  Created by Salvatore  Polito on 22/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Squadra_Partita_hpp
#define Squadra_Partita_hpp
#include <iostream>
#include <string>

class Squadra {
    std::string nome;
    
public:
    Squadra();
    
    void setNome(const std::string&);
    const std::string& getNome() const;
};

class Partita {
    Squadra *sq1, *sq2;
    int risSq1, risSq2;
    bool status;
    
public:
    Partita();
    Partita (Squadra&, Squadra&);
    
    void setRisultato(bool, int); //se chiamata con 0 si riferisce ad sq1
    void setRisultato();
    int getRisSq1() const;
    int getRisSq2() const;
    
    void cancellaRisultato();
    void stampaRisultato() const;
    bool isPlayed() const;
    void stampaNomePartita() const;
    
    Squadra& getSquadra(bool);
    const Squadra& getSquadra(bool) const;
    void addSquadra(bool, const Squadra&);
};
#endif /* Squadra_Partita_hpp */
