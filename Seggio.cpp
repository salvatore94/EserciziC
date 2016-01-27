//
//  Seggio.cpp
//  Elezioni Rappresentanti Studenti
//
//  Created by Salvatore  Polito on 26/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Seggio.hpp"
Seggio::Seggio(){
    //Creo 5 studenti per test
    Studente s1(1, 1, "s1", "s1");
    Studente s2(2, 2, "s2", "s2");
    Studente s3(3, 3, "s3", "s3");
    Studente s4(4, 4, "s4", "s4");
    Studente s5(5, 5, "s5", "s5");
    
    this->aggiungiStudente(s1);
    this->aggiungiStudente(s2);
    this->aggiungiStudente(s3);
    this->aggiungiStudente(s4);
    this->aggiungiStudente(s5);
    
    //Creo 3 candidati per test
    Candidato c1(1, 1, "c1", "c1", "lista1");
    Candidato c2(2, 2, "c2", "c2", "lista2");
    Candidato c3(3, 3, "c3", "c3", "lista3");
    
    this->aggiungiCandidato(c1);
    this->aggiungiCandidato(c2);
    this->aggiungiCandidato(c3);
    
    for(int i=0; i<=listaCandidati.size(); i++)
        voti.push_back(0);
    
    schedeBianche=0;
    schedeNulle=0;
    
    for (int i=0; i<=listaStudenti.size(); i++)
        listavotanti.push_back(false);
}

bool Seggio::giàVotato (long _m){
    int pos=this->cercaStudentePerMatricola(_m);
    if(listavotanti[pos]==true)
        return true;
    else
        return false;
}

int Seggio::numeroVotanti()  {
    int count=0;
    for(int i=0; i<=listavotanti.size(); i++)
        if(listavotanti[i]==true)
            count++;
    
    return count;
}

void Seggio::vota(int _pos){
    if(_pos >=0 && _pos<=listaCandidati.size())
        ++voti[_pos];
    else if (_pos==-1)
        schedeBianche++;
    else if(_pos>listaCandidati.size())
        schedeNulle++;
    
}

Studente& Seggio::getStudente(int _pos) {
    if(_pos >=0 && _pos<=listaStudenti.size())
        return listaStudenti[_pos];
    else
        return listaStudenti[0];
}
Candidato& Seggio::getCandidato(int _pos){
    if(_pos >=0 && _pos<=listaCandidati.size())
        return listaCandidati[_pos];
    else
        return listaCandidati[0];
}

void Seggio::aggiungiStudente( Studente &toadd){
    if(this->cercaStudentePerMatricola(toadd.getMatricola())==-1)
        listaStudenti.push_back(toadd);
    else
        std::cout << "Studente già presente!" << std::endl;
}
void Seggio::aggiungiCandidato(Candidato &toadd){
    if(this->cercaCandidatoPerMatricola(toadd.getMatricola())==-1)
        listaCandidati.push_back(toadd);
    else
        std::cout << "Candidato già presente!" << std::endl;
}

int Seggio::cercaStudentePerMatricola(long _m) {
    int pos=-1;
    for(int i=0; i!=listaStudenti.size(); i++)
        if(this->getStudente(i).getMatricola() == _m )
            pos=i;
    return pos;
}
int Seggio::cercaCandidatoPerMatricola(long _m) {
    int pos=-1;
    for(int i=0; i!=listaCandidati.size(); i++)
        if(this->getCandidato(i).getMatricola() == _m )
            pos=i;
    return pos;
}
void Seggio::stampaListaCandidati()  {
        for(int i=0; i!=listaCandidati.size(); i++)
            std::cout << i + 1  << ". " << this->getCandidato(i) << std::endl;
            
    }
void Seggio::aggiungiVoto(){
    long m=-1, cc=-1;
    std::cout << "Inserire matricola e codice di controllo:" << std::endl;
    std::cin >> m >> cc;
    int x=-1;
    x=this->cercaStudentePerMatricola(m);
    if(x==-1) {
        std::cout << "Matricola non trovata!" << std::endl;
        this->aggiungiVoto();
    }
    else {
        if(this->getStudente(x).isValid(cc)) {
            if (this->giàVotato(m)==false){
                this->stampaListaCandidati();
                std::cout << "Inserire il numero del candidato al quale si vuole assegnare il voto: (0 scheda bianca) ";
                int scelta=-1;
                std::cin >> scelta;
                this->vota(scelta - 1 );
                std::cout << "Votazione effettuata!"<< std::endl;
                this->stampaVotazione();
                listavotanti[x]=1;
            }
            else
                std::cout << "Lo studente ha già votato! " << std::endl;
        }
        else {
            std::cout << "Codice di controllo errato!" << std::endl;
            this->aggiungiVoto();
        }
    }
}

void Seggio::stampaVotazione() {
    std::cout << "Spoglio"
    <<"\n==============\n"
    << "\nNumero Votanti: " << this->numeroVotanti()
    <<"\nNumero schede bianche: " << this->schedeBianche
    <<"\nNumero voti nulli: " <<this->schedeNulle
    << "\n  Candidato  :           voti ricevuti" << std::endl;
    
    for(int i=0; i<listaCandidati.size(); i++)
        std::cout << listaCandidati[i] << " : " << voti[i] << std::endl;
    
}
