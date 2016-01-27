//
//  Seggio.hpp
//  Elezioni Rappresentanti Studenti
//
//  Created by Salvatore  Polito on 26/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Seggio_hpp
#define Seggio_hpp

#include <iostream>
#include <vector>
#include "Studente.hpp"
#include "Candidato.hpp"

class Seggio {
    std::vector<Studente> listaStudenti; //massimo 200
    std::vector<Candidato> listaCandidati; //massimo 10
    
    std::vector<int> voti;
    int schedeBianche, schedeNulle;
    
    void vota(int);
    
    std::vector<bool> listavotanti;
    bool giàVotato (long);
    int numeroVotanti() ;
public:
    Seggio();
    
    void aggiungiStudente( Studente&);
    void aggiungiCandidato(Candidato&);
    
    Studente& getStudente(int);
    Candidato& getCandidato(int);
    
    int cercaStudentePerMatricola(long) ;
    int cercaCandidatoPerMatricola(long) ;
    
    void stampaListaCandidati() ;
    void aggiungiVoto();
    void stampaVotazione() ;
    
};

#endif /* Seggio_hpp */
