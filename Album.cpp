//
//  Album.cpp
//  iTunes
//
//  Created by Salvatore  Polito on 31/12/15.
//  Copyright © 2015 Salvatore  Polito. All rights reserved.
//

#include "Album.hpp"


Album::Album (int _id, std::string _titolo, std::string _autore, int _anno) {
    this->setId(_id);
    this->setTitoloAlbum(_titolo);
    this->setAutoreAlbum(_autore),
    this->setAnnoAlbum(_anno);
    
    
}

void Album::addBrano (Brano &_toadd){
    if (data.size() <=20)
        data.push_back(_toadd);
    else
        std::cout << "Limite di brani raggiunto" << std::endl;
}

void Album::setId(int _id) {
    if(_id)
        if (_id!=this->getIdAlbum())
            identificativo=_id;
}

void Album::setTitoloAlbum(const std::string &_titolo){
    if(! _titolo.empty())
        if (this->getTitoloAlbum() != _titolo)
            titolo = _titolo;
}

void Album::setAutoreAlbum(const std::string &_autore) {
    if (! _autore.empty())
        if (this->getAutoreAlbum() != _autore)
            autore=_autore;
}

void Album::setAnnoAlbum(int _anno) {
    if (_anno >= 1800 && (this->getAnnoAlbum()!=_anno))
        anno = _anno;
}

std::ostream& Album::stampaListaBrani(std::ostream &os) {
    for (int i: data)       //perchè non usare il range for?
        os << i << ". " << ((this->getBranoAlbum(i)).getTitolo()) << std::endl;
    
    return os;
}

