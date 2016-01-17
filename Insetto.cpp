//
//  Insetto.cpp
//  Simulazione Labirinto 1
//
//  Created by Salvatore  Polito on 16/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Insetto.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
int randomPos () {
 //   std::srand(unsigned (time(0)));
    return rand()%2;
}		//restituisce o 0 oppure 1

int direzione () {
 //   std::srand(unsigned (time(0)));
    return rand()%4;
}


Formica::Formica(Labirinto *_luogo, std::string _id) {
    this->setId(_id);
    this->setLuogo(_luogo);
}


Scarabeo::Scarabeo(Labirinto *_luogo, std::string _id) {
    this->setId(_id);
    this->setLuogo(_luogo);
}

Ragno::Ragno(Labirinto *_luogo, std::string _id) : lastMove(0){
    this->setId(_id);
    this->setLuogo(_luogo);
}

void Ragno::setLastMove (int _new) {
    if (_new >0 && _new<5 && _new!= this->getLastMove())
        lastMove=_new;
}

void Scarabeo::muovi() {
    if (this->getLuogo()->isAccessible(this->getX(), this->getY()+1)) 			 //nord
        this->setY( y+1 );
    else if (this->getLuogo()->isAccessible(this->getX()+1, this->getY())) 	 //est
        this->setX( x+1 );
    else if (this->getLuogo()->isAccessible(this->getX(), this->getY()-1))      //sud
        this->setY( y-1 );
    else if (this->getLuogo()->isAccessible(this->getX()-1, this->getY())) 	 //ovest
        this->setX( x-1 );
}

void Formica::muovi() {
//    x+1 se esce 0 --->EST
//    x-1 se esce 1 --->OVEST
//    y+1 se esce 2 --->NORD
//    y-1 se esce 3 --->SUD
    int temp=direzione();
    
    switch (temp) {
        case 0:{
            if(this->getLuogo()->isAccessible(this->getX()+1, this->getY()))
                this->setX(this->getX()+1);
            else
                this->muovi();
            break;}
        case 1:{
            if (this->getLuogo()->isAccessible(this->getX()-1, this->getY()))
                this->setX(this->getX()-1);
            else
                this->muovi();
            break;}
        case 2:{
            if (this->getLuogo()->isAccessible(this->getX(), this->getY())+1)
                this->setY(this->getY()+1);
            else
                this->muovi();
            break;}
        case 3:{
            if (this->getLuogo()->isAccessible(this->getX(), this->getY()-1))
                this->setY(this->getY()-1);
            else
                this->muovi();
            break;}
    }
    
}

//void Formica::muovi() {
//    // x+1, y      se esce 1		se esce 0
//    // x-1, y  	   se esce 0
//    // x, y+1      se esce 1		se esce 1
//    // x, y-1  	   se esce 0
//    if (randomPos() == 0)/*modifico la X*/ {
//        if(randomPos() == 0) {
//            if (this->getLuogo()->isAccessible(this->getX()-1, this->getY()))
//                this->setX( x-1 );
//            else
//                this->muovi();
//        }
//        
//        if (randomPos() == 1) {
//            if (this->getLuogo()->isAccessible(this->getX()+1, this->getY()))
//                this->setX( x+1 );
//            else
//                this->muovi();
//        }
//    }
//    else if (randomPos() == 1) /*modifico la Y */ {
//        if (randomPos() == 0){
//            if (randomPos() == 0) {
//                if (this->getLuogo()->isAccessible(this->getX(), this->getY()-1))
//                    this->setY( y-1 );
//                else
//                    this->muovi();
//            }
//            if (randomPos() == 1) { 
//                if (this->getLuogo()->isAccessible(this->getX(), this->getY()+1))
//                    this->setY( y+1 );
//                else
//                    this->muovi();
//            }
//        }
//    }
//}


bool Ragno::isTheOnlyWay (const int last)  {
    /*
     0  --> fermo
     1 --> nord
     2 --> est
     3 -->ovest
     4 --> sud
     */
    
    switch (last) {
        case 1: { //nord
            if (this->getLuogo()->isAccessible(this->getX()-1, this->getY()))
                return false;
            else if (this->getLuogo()->isAccessible(this->getX()+1, this->getY()))
                return false;
            else if (this->getLuogo()->isAccessible(this->getX(), this->getY()-1))
                return false;
            else if (this->getLuogo()->isAccessible(this->getX(), this->getY()+1))
                return true;
        }
        case 2: { //est
            if (this->getLuogo()->isAccessible(this->getX(), this->getY()+1))
                return false;
            else if (this->getLuogo()->isAccessible(this->getX(), this->getY()-1))
                return false;
            else if (this->getLuogo()->isAccessible(this->getX()-1, this->getY()))
                return false;
            else if (this->getLuogo()->isAccessible(this->getX()+1, this->getY()))
                return true;
        }
        case 3: { //ovest
            if (this->getLuogo()->isAccessible(this->getX()+1, this->getY()))
                return false;
            else if (this->getLuogo()->isAccessible(this->getX(), this->getY()+1))
                return false;
            else if (this->getLuogo()->isAccessible(this->getX(), this->getY()-1))
                return false;
            else if (this->getLuogo()->isAccessible(this->getX()-1, this->getY()))
                return true;
        }
        case 4: { //sud
            if (this->getLuogo()->isAccessible(this->getX()-1, this->getY()))
                return false;
            else if (this->getLuogo()->isAccessible(this->getX()+1, this->getY()))
                return false;
            else if (this->getLuogo()->isAccessible(this->getX(), this->getY()+1))
                return false;
            else if (this->getLuogo()->isAccessible(this->getX(), this->getY()-1))
                return true;
        }
    }
    
    return false;
}

void Ragno::muovi () {
    //partenza da fermo
    if (this->getLastMove() == 0){
        if (randomPos() == 0)/*modifico la X*/ {
            if(randomPos() == 0) {
                if (this->getLuogo()->isAccessible(this->getX()-1, this->getY())) {
                    this->setX( x-1 );
                    this->setLastMove(3);}  //salvo la direzione (ovest)
                else
                    this->muovi();
            }
            
            if (randomPos() == 1) {
                if (this->getLuogo()->isAccessible(this->getX()+1, this->getY())) {
                    this->setX( x+1 );
                    this->setLastMove(2);} //salvo la direzione (est)
            }
            else
                this->muovi();
        }
        
        else if (randomPos() == 1) /*modifico la Y */ {
            if (randomPos() == 0){
                if (randomPos() == 0) {
                    if (this->getLuogo()->isAccessible(this->getX(), this->getY()-1)) {
                        this->setY( y-1 );
                        this->setLastMove(4);}		//salvo la posizione (sud)
                    else
                        this->muovi();
                }
                if (randomPos() == 1) {
                    if (this->getLuogo()->isAccessible(this->getX(), this->getY()+1)) {
                        this->setY( y+1 );
                        this->setLastMove (1);} // salvo la posizione (nord)
                }
                else
                    this->muovi();
            }
        }
    }
    //scorsa posizione nord
    if(this->getLastMove() == 1){
        if (isTheOnlyWay(1) == true) {
            this->setY( y+1 );
            this->setLastMove (1); // salvo la posizione (nord)
        }
        else {
            if (randomPos() == 0)/*modifico la X*/ {
                if(randomPos() == 0) {
                    if (this->getLuogo()->isAccessible(this->getX()-1, this->getY())) {
                        this->setX( x-1 );
                        this->setLastMove(3);}  //salvo la direzione (ovest)
                    else
                        this->muovi();
                }
                
                if (randomPos() == 1) {
                    if (this->getLuogo()->isAccessible(this->getX()+1, this->getY())) {
                        this->setX( x+1 );
                        this->setLastMove(2);} //salvo la direzione (est)
                }
                else
                    this->muovi();
            }
            
            else if (randomPos() == 1) /*modifico la Y */ {
                if (randomPos() == 0){
                    if (randomPos() == 0) {
                        if (this->getLuogo()->isAccessible(this->getX(), this->getY()-1)) {}
                        this->setY( y-1 );
                        this->setLastMove(4);}		//salvo la posizione (sud)
                    else
                        this->muovi();
                }
                if (randomPos() == 1)
                    this->muovi();
            }
            
        }
    }
    //scorsa posizione est
    if (this->getLastMove() == 2){
        if (isTheOnlyWay(2) == true) {
            this->setX( x+1 );
            this->setLastMove (2); // salvo la posizione (nord)
        }
        else {
            if (randomPos() == 0)/*modifico la X*/ {
                if(randomPos() == 0) {
                    if (this->getLuogo()->isAccessible(this->getX()-1, this->getY())) {
                        this->setX( x-1 );
                        this->setLastMove(3);}  //salvo la direzione (ovest)
                    else
                        this->muovi();
                }
                
                if (randomPos() == 1) {
                    this->muovi();
                }
                
                else if (randomPos() == 1) /*modifico la Y */ {
                    if (randomPos() == 0){
                        if (randomPos() == 0) {
                            if (this->getLuogo()->isAccessible(this->getX(), this->getY()-1)) {
                                this->setY( y-1 );
                                this->setLastMove(4);}		//salvo la posizione (sud)
                            else
                                this->muovi();
                        }
                        if (randomPos() == 1) {
                            if (this->getLuogo()->isAccessible(this->getX(), this->getY()+1)) {
                                this->setY( y+1 );
                                this->setLastMove (1);} // salvo la posizione (nord)
                        }
                        else
                            this->muovi();
                    }
                }
            }
        }
    }
    // scorsa posizione ovest
    if (this->getLastMove() == 3){
        if (isTheOnlyWay(3) == true) {
            this->setX( x-1 );
            this->setLastMove (3); // salvo la posizione (ovest)
        }
        else {
            if (randomPos() == 0)/*modifico la X*/ {
                if(randomPos() == 0) {
                    this->muovi();
                }
                
                if (randomPos() == 1) { 
                    if (this->getLuogo()->isAccessible(this->getX()+1, this->getY())) {
                        this->setX( x+1 );
                        this->setLastMove(2);} //salvo la direzione (est)
                    
                    else
                        this->muovi();
                }
                
                else if (randomPos() == 1) /*modifico la Y */ {
                    if (randomPos() == 0){
                        if (randomPos() == 0) { 
                            if (this->getLuogo()->isAccessible(this->getX(), this->getY()-1)) {
                                this->setY( y-1 ); 
                                this->setLastMove(4);}		//salvo la posizione (sud)
                            else
                                this->muovi();
                        }
                        if (randomPos() == 1) { 
                            if (this->getLuogo()->isAccessible(this->getX(), this->getY()+1)) {
                                this->setY( y+1 );
                                this->setLastMove (1);} // salvo la posizione (nord)
                        }
                        else
                            this->muovi();
                    }
                }
            }
        }
    }
    //scorsa posizione sud
    if (this->getLastMove() == 4) {
        if (isTheOnlyWay(4) == true) {
            this->setY( y-1 );
            this->setLastMove (4); // salvo la posizione (nord)
        }
        else {
            if (randomPos() == 0)/*modifico la X*/ {
                if(randomPos() == 0) {
                    if (this->getLuogo()->isAccessible(this->getX()-1, this->getY())) {
                        this->setX( x-1 );
                        this->setLastMove(3);}  //salvo la direzione (ovest)
                    else 
                        this->muovi();
                }
                
                if (randomPos() == 1) { 
                    if (this->getLuogo()->isAccessible(this->getX()+1, this->getY())) {
                        this->setX( x+1 );
                        this->setLastMove(2);} //salvo la direzione (est)
                }
                else
                    this->muovi();
            }
            
            else if (randomPos() == 1) /*modifico la Y */ {
                if (randomPos() == 0){
                    if (randomPos() == 0) { 
                        this->muovi();
                    }
                    if (randomPos() == 1) { 
                        if (this->getLuogo()->isAccessible(this->getX(), this->getY()+1)) {
                            this->setY( y+1 );
                            this->setLastMove (1);} // salvo la posizione (nord)
                    }
                    else
                        this->muovi();
                }
            }
        }
    }
}