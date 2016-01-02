//
//  Archivio.cpp
//  iTunes
//
//  Created by Salvatore  Polito on 02/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#include "Archivio.hpp"
void Archivio::addAlbum(const Album &toadd) {
    int count=0;
    for(int i=0; i!= this->dataAlbum.size(); ++i)
    //for(std::vector<Album&>::std::iterator it: dataAlbum)
        if(this->getAlbum(i).getTitoloAlbum() == toadd.getTitoloAlbum())
            ++count;
    if(count==0)
        dataAlbum.push_back(toadd);
    else
        std::cout << "Album già presente" << std::endl;
}

void Archivio::addPlaylist(const Playlist &toadd) {
    int count=0;
    for(int i=0; i!= this->dataPlaylist.size(); ++i)
        //for(std::vector<Album&>::std::iterator it: dataAlbum)
        if(this->getPlaylist(i).getNomePlaylist() == toadd.getNomePlaylist())
            ++count;
    if(count==0)
        dataPlaylist.push_back(toadd);
    else
        std::cout << "Playlist già presente" << std::endl;
}

std::ostream& Archivio::stampaAlbum(std::ostream &os) {
    for (int i=0; i!= this->dataAlbum.size(); ++i){
        os << i << ". " ;
    this->getAlbum(i).stampaListaBrani(os);
    os << std::endl;
    }
    return os;
}

std::ostream& Archivio::stampaPlaylist(std::ostream &os) {
    for (int i=0; i!= this->dataPlaylist.size(); ++i) {
        os << i << ". ";
    this->getPlaylist(i).stampaListaBrani(os);
    os << std::endl;
    }
    return os;
}