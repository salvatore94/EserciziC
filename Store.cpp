//
//  Store.cpp
//  GestioneApplicazioni
//
//  Created by Salvatore  Polito on 07/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//


//void Store::addApplicazione(const long _id, const std::string &_nome, const std::string &_descrione,const int _versione){
//    int segno=0;
//    for(int i=0; i!= this->getSize(); ++i){
//        if(this->getApplicazione(i).getId() == _id && segno==0) {
//            this->getApplicazione(i).setNome(_nome);
//            this->getApplicazione(i).setDescrizione(_descrione);
//            this->getApplicazione(i).setVersione(_versione);
//            ++segno;
//        }
//    }
//        if (segno==0){
//            Applicazione temp(_id, _nome, _descrione, _versione);
//            this->storeData.push_back(temp);
//        }
//}

#include "Store.h"

void Store::addApplicazione(const Applicazione &toadd){
    int segno=0;
    for(int i=0; i!= this->getSize(); ++i){
        if(this->getApplicazione(i).getId() == toadd.getId() && segno==0){
            this->getApplicazione(i).setNome(toadd.getNome());
            this->getApplicazione(i).setDescrizione(toadd.getDescrizione());
            this->getApplicazione(i).setVersione(toadd.getVersione());
        }
    }
    if(segno ==0){
        this->storeData.push_back(toadd);
    }
}

void Store::removeApplicazione(long _id) {
    for(int i=0; i!= this->getSize(); ++i){
        if (this->getApplicazione(i).getId() == _id)
            this->storeData.erase(this->storeData.begin() +i );
    }
    
}

void Store::stampaListaApplicazioni(std::ostream &os) const {
    for (int i=0; i!= this->getSize(); ++i)
        std::cout << i << ". " << this->getApplicazione(i).getNome() << std::endl;
}