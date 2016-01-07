//
//  Applicazione.cpp
//  GestioneApplicazioni
//
//  Created by Salvatore  Polito on 07/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//
#ifndef APPLICAZIONE_INCLUDED
#define APPLICAZIONE_INCLUDED
#include <string>
class Applicazione {
protected:
    long id;
    std::string nome, descrizione;
    int versione;
    
public:
    Applicazione () :Applicazione (0, "NoName", 0) {};
    Applicazione (long ___id, const std::string &___nome, int ___ver) : Applicazione(___id, ___nome, "---", ___ver) {};
    Applicazione (long __id, const std::string &__nome, const std::string &__des, int __ver) {
        this->setId(__id);
        this->setNome(__nome);
        this->setDescrizione(__des);
        this->setVersione(__ver);
    }
    
    void setId (long _id) {if (_id>=0 && _id!=id) id=_id;}
    void setNome (const std::string &_nome) {nome=_nome;}
    void setDescrizione (const std::string &_des) {descrizione=_des;}
    void setVersione (int _ver) {if(versione >= _ver) versione=_ver;}
    
    long getId () const {return id;}
    const std::string& getNome () const {return nome;}
    const std::string& getDescrizione () const {return descrizione;}
    int getVersione () const {return versione;}
};
#endif

