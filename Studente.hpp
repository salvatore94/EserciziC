//
//  Studente.hpp
//  Elezioni Rappresentanti Studenti
//
//  Created by Salvatore  Polito on 26/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Studente_hpp
#define Studente_hpp

#include <iostream>
#include <string>

class Studente {
    long matricola, codiceControllo;
    std::string nome, cognome;
    
public:
    Studente();
    Studente(long, long, const std::string&, const std::string&);
    
    void setMatricola(long);
    void setCodiceControllo(long);
    void setNomeStudente(const std::string&);
    void setCognomeStudente(const std::string &nS);
    
    long getMatricola() const;
    long getCodiceControllo() const;
    const std::string& getNomeStudente() const;
    const std::string& getCognomeStudente() const;
    
    bool isValid(long);
};

std::istream& operator>> (std::istream&, Studente&);
std::ostream& operator<< (std::ostream&, Studente&);

#endif /* Studente_hpp */
