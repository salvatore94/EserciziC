//
//  Labirinto.hpp
//  Simulazione Labirinto 1
//
//  Created by Salvatore  Polito on 16/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Labirinto_hpp
#define Labirinto_hpp
#include "Insetto.hpp"
class Insetto;

class Labirinto {
    bool tabella[11][11];
    Insetto* tabellaInsetti[10];
    int nInsetti;
    
public:
    Labirinto ();
//    ~Labirinto ();
    
    bool isAccessible(int, int) const;
    bool isOut (int) const;
    void addInsetto (Insetto*);
    void Run (int);
    void stampaLabirinto (std::ostream&) const;
    void stampaListaInsetti (std::ostream&);
};

#endif /* Labirinto_hpp */
