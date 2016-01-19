//
//  Archivio.hpp
//  Archivio Foto
//
//  Created by Salvatore  Polito on 18/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef Archivio_hpp
#define Archivio_hpp

#include "Persona.hpp"
#include "Foto.hpp"

#include <string>

class Archivio {
    int count;
    std::string nomeArchivio;
    Foto** dataPtr =new Foto*[count];
    
public:
    Archivio () : Archivio("") {}
    Archivio (const std::string&);
    ~Archivio();
    
    const std::string& getNomeArchivio () const;
    const std::string& getNomeArchivio ();
    void setNomeArchivio(const std::string&);
    void addFoto (Foto*);
    
    Foto* getFoto(int _pos) const;
    Foto* getFoto(int _pos);
    int cercaFoto (const std::string&) const;
    int getSize () const;
    
    void modificaFoto();
    void cercaPerLuogo ();
    void cercaPerSoggetto ();
    
    void printAll () const;
};

#endif /* Archivio_hpp */
