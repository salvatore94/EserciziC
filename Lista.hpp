//
//  Lista.hpp
//  ListaConcatenata
//
//  Created by Salvatore  Polito on 26/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Lista_hpp
#define Lista_hpp
#include <iostream>

#include "Nodo.hpp"

class Lista {
    Nodo *next, *current;
    int lunghezza;
    
public:
    Lista();
    Lista(Nodo&);
    
    Nodo& spostaAvanti();
    Nodo& getCurrent();
    Nodo& getNodo(int);
    
    void aggiungiNodo(Nodo&);
    void rimuoviNodo(int);
    
    Lista& operator= (Lista&);
    bool operator== (Lista&) ;
    bool operator!= (Lista&) ;
    
    int getLunghezza() const;
};

std::ostream& operator<< (std::ostream&, Lista&);
#endif /* Lista_hpp */
