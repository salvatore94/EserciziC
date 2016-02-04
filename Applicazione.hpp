//
//  Applicazione.hpp
//  Gestione Applicazioni (1)
//
//  Created by Salvatore  Polito on 02/02/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Applicazione_hpp
#define Applicazione_hpp

#include <iostream>
#include <string>

class Applicazione {
    long id;
    std::string nomeApplicazione, descrizioneApplicazione;
    int versione;
    
public:
    Applicazione(); //Richiede tutti i dati
    
    void setId(long);
    void setVersione(int);
    void setNomeApplicazione(const std::string&);
    void setDescrizioneApplicazione(const std::string&);
    
    long getId();
    int getVersione();
    const std::string& getNomeApplicazione();
    const std::string& getDescrizioneApplicazione();
};
std::ostream& operator<< (std::ostream&,  Applicazione&);
std::istream& operator>> (std::istream&, Applicazione&);
#endif /* Applicazione_hpp */
