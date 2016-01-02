//
//  Album.hpp
//  iTunes
//
//  Created by Salvatore  Polito on 31/12/15.
//  Copyright © 2015 Salvatore  Polito. All rights reserved.
//

#ifndef Album_hpp
#define Album_hpp

#include "Brano.hpp"
#include <iostream>
#include <vector>

class Album {
    int identificativo;
    std::string titolo;
    std::string autore;
    int anno;       //minimo valore possibile 1800
    
    std::vector<Brano&> data;
   

public:
    Album();
    Album (int, std::string, std::string, int);
    
    
    void setId (int);
    void setTitoloAlbum (const std::string&);
    void setAutoreAlbum (const std::string&);
    void setAnnoAlbum (int);
    void addBrano (Brano&);
    
    int getIdAlbum () const { return identificativo;}
    std::string getTitoloAlbum () const {return titolo;}
    std::string getAutoreAlbum () const {return autore;}
    int getAnnoAlbum () const {return anno;}
    int getSizeAlbum () const {return data.size();}
    Brano& getBranoAlbum (int pos) const {return data[pos];}
    
    std::ostream& stampaListaBrani(std::ostream&);
};

#endif /* Album_hpp */
