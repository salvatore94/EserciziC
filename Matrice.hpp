//
//  Matrice.hpp
//  Matrici Rettangolari
//
//  Created by Salvatore  Polito on 04/02/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Matrice_hpp
#define Matrice_hpp

#include <iostream>

class Matrice {
    int **data;
    int nRighe, nColonne;
    
    void crea(int, int);
    void distruggi();
    bool sameLen(Matrice&);
    
public:
    Matrice();
    Matrice(int, int);
    Matrice(Matrice&);
    
    ~Matrice();
    
    int getRighe();
    int getColonne();
    
    Matrice& operator= (Matrice&);
    Matrice& operator+ (Matrice&);
    Matrice& operator- (Matrice&);
    
    int& at(int, int);
};
std::istream& operator>> (std::istream&, Matrice&);
std::ostream& operator<< (std::ostream&, Matrice&);

#endif /* Matrice_hpp */
