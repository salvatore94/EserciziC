//
//  Insetto.hpp
//  Simulazione Labirinto 1
//
//  Created by Salvatore  Polito on 16/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Insetto_hpp
#define Insetto_hpp
#include <string>
#include "Labirinto.hpp"
class Labirinto;
class Insetto {
protected:
    int x;
    int y;
    
    std::string identificativo;
    Labirinto *luogo;
    
public:
    Insetto() {luogo=0;}
    void virtual muovi()=0;

    
    std::string  getIdentificativo () const {return identificativo;}
    const Labirinto* getLuogo () {return luogo;}
    int getX () const {return x;}
    int getY() const {return y;}
    
    void setLuogo (Labirinto *_luogo) {luogo=_luogo;}
    void setId (std::string _id) {identificativo=_id;}
    void setX( int _x) {x=_x;}
    void setY (int _y) {y=_y;}
};


class Formica : public Insetto {
    
public:
    Formica (Labirinto*, std::string);
    void muovi();

};
class Scarabeo : public Insetto {
    
public:
    Scarabeo (Labirinto*, std::string);
    void muovi();
};

class Ragno : public Insetto {
    short lastMove;
    
public:
    Ragno(Labirinto*, std::string);
    
    short getLastMove() const {return lastMove;}
    void setLastMove(int);
    bool isTheOnlyWay (const int)  ;
    
    void muovi();
};
#endif /* Insetto_hpp */
