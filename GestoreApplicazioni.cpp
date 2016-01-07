//
//  GestoreApplicazioni.cpp
//  GestioneApplicazioni
//
//  Created by Salvatore  Polito on 07/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "GestoreApplicazioni.h"
void GestoreApplicazioni::rimuoviApplicazione(long _id) {
    for(int i=0; i!= this->getSize(); ++i){
        if(this->getApplicazioneInstallata(i).getId() == _id)
            this->dataGestoreApplicazione.erase(this->dataGestoreApplicazione.begin()+i);
    }
}

void GestoreApplicazioni::stampaDettagli(std::ostream &os) {
    std::cout << "Lista Applicazioni Installate" << std::endl;
    for(int i=0; i!=this->getSize(); ++i)
        std::cout << i +1  << ". " << this->getApplicazioneInstallata(i).getId() << "  <-->  " << this->getApplicazioneInstallata(i).getNome() << "  <-->  " << this->getApplicazioneInstallata(i).getVersione() << std::endl;
}

void GestoreApplicazioni::aggiornaApplicazioni(const Store &_store) {
    
}




void GestoreApplicazioni::aggiungiApplicazione(const Store &_store) {
    char scelta='n';
    std::cout << "Accettare tramite la lettera y" << std::endl;
    for( int i=0; i!= _store.getSize(); ++i){
        std::cout <<"Installare: "<< _store.getApplicazione(i).getNome() <<"   ?" << std::endl;
        std::cin >> scelta;
        
        if (scelta=='y') {
            Applicazione temp = _store.getApplicazione(i);
        
            ApplicazioneInstallata toadd(temp.getId(), temp.getNome(), temp.getDescrizione(), temp.getVersione());
            toadd.setMemoriaOccupata(this->generateMemoriaUsata());
        
            this->dataGestoreApplicazione.push_back(toadd);
        }
    }
}


