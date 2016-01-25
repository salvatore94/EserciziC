//
//  Cinema.hpp
//  Biglietteria Cinema
//
//  Created by Salvatore  Polito on 25/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Cinema_hpp
#define Cinema_hpp

#include "Sala.hpp"
#include "Biglietto.hpp"
#include <vector>

class Cinema {
    Sala listaSala[4];
    std::vector<Biglietto*> listaBiglietti;
    
    int cercaSala (char);
public:
    Cinema();
    
    void aggiungiBiglietto( Biglietto&);
    
    Biglietto& getBiglietto(int);
    
    void stampaPostiLiberiTutteLeSale();
    void emissioneBiglietto();
    void resettaSala();


};

#endif /* Cinema_hpp */
