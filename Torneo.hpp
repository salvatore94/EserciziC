//
//  Torneo.hpp
//  Torneo di Calcio
//
//  Created by Salvatore  Polito on 22/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Torneo_hpp
#define Torneo_hpp

#include "Girone.hpp"
#include <vector>

class Torneo {
    Squadra *listaSquadre[12];
    Girone *listaGironi[4];
    
    
public:
    Torneo();
    
    void addSquadraTorneo(int, Squadra&);
    Squadra& getSquadra(int);
    
    void addGironeTorneo(int, Girone&);
    Girone& getGirone(int);
    
    void setRisultato();
    void stampaStatoGirone();
    void stampaTuttiIGironi();
    void cancellaTuttiIRisultati();
};

#endif /* Torneo_hpp */
