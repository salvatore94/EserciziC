//
//  GestoreApplicazioni.h
//  GestioneApplicazioni
//
//  Created by Salvatore  Polito on 08/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef GESTOREAPPLICAZIONI_INCLUDED
#define GESTOREAPPLICAZIONI_INCLUDED

#include "ApplicazioneInstallata.cpp"
#include <vector>
#include <iostream>
#include "Store.h"

class GestoreApplicazioni {
    std::vector<ApplicazioneInstallata> dataGestoreApplicazione;
    long generateMemoriaUsata() const {return (rand() % 1901) + 100;}
    
public:
    GestoreApplicazioni () = default;
    
    size_t getSize() const {return dataGestoreApplicazione.size();}
    ApplicazioneInstallata& getApplicazioneInstallata (const int pos) {return dataGestoreApplicazione[pos];}
    
    void stampaDettagli (std::ostream &);
    void rimuoviApplicazione (long ); //ricerca l'id e se è presente rimuove l'app
    void aggiungiApplicazione (const Store&);
    void aggiornaApplicazioni (const Store&);
};
#endif /* GestoreApplicazioni_h */
