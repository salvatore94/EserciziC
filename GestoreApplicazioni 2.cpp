//
//  GestoreApplicazioni.cpp
//  Gestione Applicazioni (1)
//
//  Created by Salvatore  Polito on 02/02/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "GestoreApplicazioni.hpp"
GestoreApplicazioni::GestoreApplicazioni()=default;

void GestoreApplicazioni::stampaAppInstallate() {
    std::cout << "=================="
    <<"\nLista Applicazioni Installate" << std::endl;
    for(int i=0; i<appInstallate.size(); i++)
        std::cout << appInstallate[i];
    std::cout << "==================" << std::endl;
}

int GestoreApplicazioni::cercaPerId(long n) {
    for (int i=0; i<appInstallate.size(); i++)
        if(appInstallate[i].getId()== n)
            return i;
    return -1;
}

void GestoreApplicazioni::aggiorna(Store &s1) {
    int x=0;
    for(int i=0; i<appInstallate.size(); i++) {
        x = s1.cercaPerId(appInstallate[i].getId());
        if(x!=-1 && s1.getApplicazione(x).getVersione() > appInstallate[i].getVersione() ) {
            ApplicazioneInstallata temp(s1.getApplicazione(x));
            appInstallate[i]=temp;
        }
    }
        
}

void GestoreApplicazioni::addApplicazione(Store &s1) {
    for(int i=0; i<s1.getSize(); i++){
        std::cout << &s1.getApplicazione(i)
            <<"Premere 'y' per installare.." << std::endl;
        char c;
        std::cin >> c;
        if(c=='s') {
            ApplicazioneInstallata temp(s1.getApplicazione(i));
            appInstallate.push_back(temp);
        }
    }
}

void GestoreApplicazioni::remove() {
    long x=0;
    std::cout <<"Inserire ID dell'applicazione da rimuovere: ";
    std::cin >> x;
    x=this->cercaPerId(x);
    if(x!=-1) {
        appInstallate.erase(appInstallate.begin() + x);
        std::cout << "\n Fatto!" << std::endl;
    }
    else
        std::cout <<"\nApplicazione non presente!"<<std::endl;
}