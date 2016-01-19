//
//  Persona.hpp
//  Archivio Foto
//
//  Created by Salvatore  Polito on 18/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Persona_hpp
#define Persona_hpp
#include <iostream>
#include <string>

class Persona {
    std::string nome, cognome, dataNascita;
    
public:
    Persona () = default; //per ora
    Persona (const std::string &n, const std::string &c, const std::string &dN) : nome(n), cognome(c), dataNascita(dN) {}
    
    void setNome(const std::string&);
    void setCognome (const std::string&);
    void setDataNascita (const std::string&);
    
    const std::string& getNome () const {return nome;}
    const std::string& getCognome () const {return cognome;}
    const std::string& getDataNascita () const {return dataNascita;}
    
    friend std::ostream& operator<< (std::ostream&, const Persona&);
    friend std::istream& operator>> (std::istream&,  Persona&);
    bool operator== (const Persona&) const;
};


#endif /* Persona_hpp */
