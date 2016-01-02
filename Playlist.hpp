//
//  Playlist.hpp
//  iTunes
//
//  Created by Salvatore  Polito on 02/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Playlist_hpp
#define Playlist_hpp

#include "Brano.hpp"
#include <iostream>
#include <vector>
class Playlist {
    int identificativo;
    std::string nome;
    std::vector<Brano&> data;
    
public:
    Playlist() : Playlist (0, "---") {};
    Playlist(const int &, const std::string&);
    
    std::string getNomePlaylist () const {return nome;}
    int getIdPlaylist () const {return identificativo;}
    int getSize () const { return data.size(); }
    
    void addBrano (const Brano&);
    void setNomePlaylist (const std::string&);
    void setIdPlaylist (const int&);
    
    Brano& getBranoPlaylist (int pos) const {return data[pos];}
    
    std::ostream& stampaListaBrani (std::ostream&);
    
};
#endif /* Playlist_hpp */
