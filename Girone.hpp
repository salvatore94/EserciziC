//
//  Girone.hpp
//  Torneo di Calcio
//
//  Created by Salvatore  Polito on 22/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Girone_hpp
#define Girone_hpp
#include "Squadra_Partita.hpp"

class Girone {
    Partita partitaGirone[3];
    int counter;
public:
    Girone();
    Girone(Partita&, Partita&, Partita&);
    
    Partita& getPartita(int);
    void addPartitaGirone(int, Partita&);
    void stampaStatoGirone();
    void stampaPartiteDaGiocare();
    bool isValid();
    
    void cancellaRisultatiGirone();
};

#endif /* Girone_hpp */
