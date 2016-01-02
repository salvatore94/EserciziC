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
    for(int i: dataAlbum)
    //for(std::vector<Album&>::std::iterator it: dataAlbum)
        if(this->getAlbum(i) == toadd)
            ++count;
    if(count==0)
        dataAlbum.push_back(toadd);
    else
        std::cout << "Album già presente" << std::endl;
}

void Archivio::addPlaylist(const Playlist &toadd) {
    int count=0;
    for(int i: dataPlaylist)
        //for(std::vector<Album&>::std::iterator it: dataAlbum)
        if(this->getPlaylist(i) == toadd)
            ++count;
    if(count==0)
        dataPlaylist.push_back(toadd);
    else
        std::cout << "Playlist già presente" << std::endl;
}

std::ostream& Archivio::stampaAlbum(std::ostream &os) {
    for (int i: dataAlbum)
        std::cout << i << ". " << this->getAlbum(i).stampaListaBrani(std::cout) << std::endl;
    return os;
}

std::ostream& Archivio::stampaPlaylist(std::ostream &os) {
    for (int i: dataPlaylist)
        std::cout << i << ". " << this->getPlaylist(i).stampaListaBrani(std::cout) << std::endl;
    return os;
}