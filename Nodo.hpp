//
//  Nodo.hpp
//  ListaConcatenata
//
//  Created by Salvatore  Polito on 26/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Nodo_hpp
#define Nodo_hpp

#include <iostream>

class Nodo {
    int data;
    Nodo *next;
    
public:
    Nodo();
    Nodo(int);
    
    void setData(int);
    void setNext(Nodo&);
    
    int getData() const;
    Nodo* getNext();
};

std::ostream& operator<< (std::ostream&, Nodo&);
#endif /* Nodo_hpp */
