//
//  Playlist.cpp
//  iTunes
//
//  Created by Salvatore  Polito on 02/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Playlist.hpp"



Playlist::Playlist (const int &id, const std::string &nome) {
    this->setIdPlaylist(id);
    this->setNomePlaylist(nome);
}

void Playlist::addBrano (const Brano &_toadd) {
    if (this->getSize() <= 50)
        data.push_back(_toadd)
    else
        std::cout << "Limite brani raggiunto" << std::endl;
}

void Playlist::setNomePlaylist(const std::string &_nome) {
    if(! _nome.empty())
        if(this->getNomePlaylist() != _nome)
            nome=_nome;
}

void Playlist::setIdPlaylist(const int &_id) {
    if(_id >= 0)
        if(this->getIdPlaylist() != _id)
            identificativo=_id;
}

std::ostream& Playlist::stampaListaBrani(std::ostream &os) {
    for (int i: data)
        std::cout << i <<". " << getBranoPlaylist(i).getTitolo() << std::endl;
    return os;
}