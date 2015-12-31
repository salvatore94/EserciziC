//
//  Brano.cpp
//  iTunes
//
//  Created by Salvatore  Polito on 31/12/15.
//  Copyright © 2015 Salvatore  Polito. All rights reserved.
//

#include "Brano.hpp"

Brano::Brano (std::string _titolo, std::string _percorso, std::string _cantante) {
    this->setTitolo(_titolo);
    this->setNomeFile(_percorso);
    this->setCantante(_cantante);
}

Brano::Brano() : Brano ("test", "", "---") //creo un oggetto  di test nel caso in cui non venisse passato nessun parametro
{
#ifdef DEBUG
    std::cout << "Costruttore di default invocato" << std::endl;
#endif
}


void Brano::setTitolo (std::string _titolo) {
    if (_titolo.empty())
        std::cout << "Titolo non valido" << std::endl;
    else if (this->getTitolo() == _titolo)
        std::cout << "Titolo identico " << std::endl;
    else
        titolo= _titolo;
}

void Brano::setNomeFile (std::string _percorso) {
    if (_percorso.empty())
       std::cout << "Percorso non valido" << std::endl;
    else if (this->getNomeFile() == _percorso)
       std::cout << "Percorso identico" << std::endl;
    else
        nomeFile = _percorso;
}

void Brano::setCantante( std::string _cantante) {
    if (_cantante.empty())
        std::cout << "Cantante non valido" << std::endl;
    else if (this->getCantante() == _cantante)
        std::cout << "Cantante identico " << std::endl;
    else
        cantante= _cantante;
}
