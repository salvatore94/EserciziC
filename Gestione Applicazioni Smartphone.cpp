//
//  main.cpp
//  GestioneApplicazioni
//
//  Created by Salvatore  Polito on 07/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include <iostream>
#include "Applicazione.cpp"
#include "GestoreApplicazioni.h"
#include "Store.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Store s1;
    Applicazione test1(8493, "test", 1), test2;
    s1.addApplicazione(test1);
    s1.addApplicazione(test2);
    s1.stampaListaApplicazioni(std::cout);
    GestoreApplicazioni g1;
    g1.aggiungiApplicazione(s1);
    
    g1.stampaDettagli(std::cout);
    s1.removeApplicazione(8493);
    g1.rimuoviApplicazione(8493);
    s1.stampaListaApplicazioni(std::cout);
    g1.stampaDettagli(std::cout);
    g1.aggiornaApplicazioni(s1);
    std::cout << "Hello, World!\n";
    return 0;
}
