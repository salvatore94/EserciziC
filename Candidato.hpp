//
//  Candidato.hpp
//  Elezioni Rappresentanti Studenti
//
//  Created by Salvatore  Polito on 26/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Candidato_hpp
#define Candidato_hpp

#include <iostream>
#include <string>
#include "Studente.hpp"

class Candidato : public Studente {
    std::string lista;
    
public:
    Candidato();
    Candidato(long, long, const std::string&, const std::string&, const std::string&);
    
    void setLista(const std::string&);
    
    const std::string& getLista() const;
};

std::istream& operator>> (std::istream&, Candidato&);
std::ostream& operator<< (std::ostream&, Candidato&);

#endif /* Candidato_hpp */
