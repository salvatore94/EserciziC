//
//  Archivio.hpp
//  iTunes
//
//  Created by Salvatore  Polito on 02/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Archivio_hpp
#define Archivio_hpp

#include "Brano.hpp"
#include "Album.hpp"
#include "Playlist.hpp"
#include <iterator>
#include <vector>

class Archivio {
    std::vector<Album&> dataAlbum;
    std::vector<Playlist&> dataPlaylist;
    const std::string nomeArchivio;
    
    Archivio () : nomeArchivio("---") {};
    Archivio (const std::string &_nome) : nomeArchivio(_nome) {};
    
    void addAlbum (const Album&);
    void addPlaylist (const Playlist&);
    
    const Album& getAlbum (int pos) const {return dataAlbum[pos];}
    const Playlist& getPlaylist (int pos) const {return dataPlaylist[pos];}
    
    std::ostream& stampaAlbum (std::ostream&);
    std::ostream& stampaPlaylist (std::ostream&);
};
#endif /* Archivio_hpp */
