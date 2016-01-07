//
//  Store.h
//  GestioneApplicazioni
//
//  Created by Salvatore  Polito on 07/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef STORE_INCLUDED
#define STORE_INCLUDED

#include "Applicazione.cpp"
#include <vector>
#include <iostream>

class Store {
    std::vector<Applicazione> storeData;
    
public:
    Store() = default;
    
    size_t getSize () const {return storeData.size();}
    Applicazione& getApplicazione (const int &pos) {return storeData[pos];}
    const Applicazione& getApplicazione (const int &pos) const {return storeData[pos];}
    
    void addApplicazione (const long, const std::string &, const std::string &, const int); //se id esiste viene sovrascritto
    void addApplicazione (const Applicazione&);
    void removeApplicazione (long); //se esiste l'id
    
    void stampaListaApplicazioni (std::ostream&) const ;
};

#endif /* Store_h */

