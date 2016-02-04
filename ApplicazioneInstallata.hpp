//
//  ApplicazioneInstallata.hpp
//  Gestione Applicazioni (1)
//
//  Created by Salvatore  Polito on 02/02/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef ApplicazioneInstallata_hpp
#define ApplicazioneInstallata_hpp

#include "Applicazione.hpp"

class ApplicazioneInstallata : public Applicazione {
    long memoriaOccupata;
    
public:
    ApplicazioneInstallata( Applicazione&);
    
    void setMemoriaOccupata(long);
    
    long getMemoriaOccupata();
    
};
std::ostream& operator<< (std::ostream&,  ApplicazioneInstallata&);
std::istream& operator>> (std::istream&, ApplicazioneInstallata&);
#endif /* ApplicazioneInstallata_hpp */
