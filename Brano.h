//
//  Brano.hpp
//  iTunes
//
//  Created by Salvatore  Polito on 31/12/15.
//  Copyright © 2015 Salvatore  Polito. All rights reserved.
//

#ifndef Brano_hpp
#define Brano_hpp

#include <string>
#include <iostream>

class Brano {
    std::string titolo, nomeFile, cantante;
    
public:
    Brano();
    Brano (std::string,std::string,std::string);
    

    
    void setTitolo (std::string);
    void setNomeFile (std::string);
    void setCantante (std::string);
    
    std::string getTitolo () const   {return titolo;}
    std::string getNomeFile () const {return nomeFile;}
    std::string getCantante () const {return cantante;}
    

};
#endif /* Brano_hpp */
