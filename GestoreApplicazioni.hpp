//
//  GestoreApplicazioni.hpp
//  Gestione Applicazioni (1)
//
//  Created by Salvatore  Polito on 02/02/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//

#ifndef GestoreApplicazioni_hpp
#define GestoreApplicazioni_hpp

#include <vector>
#include "ApplicazioneInstallata.hpp"
#include "Store.hpp"

class GestoreApplicazioni {
    std::vector<ApplicazioneInstallata> appInstallate;
    
    int cercaPerId(long);
public:
    GestoreApplicazioni();
    
    void stampaAppInstallate();
    void addApplicazione( Store&);
    void remove();
    void aggiorna( Store&);
};
#endif /* GestoreApplicazioni_hpp */
