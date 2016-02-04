//
//  Store.hpp
//  Gestione Applicazioni (1)
//
//  Created by Salvatore  Polito on 02/02/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Store_hpp
#define Store_hpp

#include <vector>
#include "Applicazione.hpp"

class Store {
    std::vector<Applicazione*> listaApplicazioni;
    
public:
    ~Store();
    
    int cercaPerId(long);
    
    void addApplicazione();
    void removeApplicazione();
    void stampaListaApplicazioni();
    
    Applicazione& getApplicazione(int);
    int getSize();
};

#endif /* Store_hpp */
