//
//  ApplicazioneInstallata.cpp
//  GestioneApplicazioni
//
//  Created by Salvatore  Polito on 07/01/16.
//  Copyright © 2016 Salvatore  Polito. All rights reserved.
//
#ifndef APPLICAZIONEINSTALLATA_INCLUDED
#define APPLICAZIONEINSTALLATA_INCLUDED

#include "Applicazione.cpp"

class ApplicazioneInstallata : public Applicazione {
    long memoriaOccupata;
    
public:
    ApplicazioneInstallata() : Applicazione() { memoriaOccupata=0 ;};
    ApplicazioneInstallata(long __id, const std::string &__nome, const std::string &__des, int __ver) : Applicazione(__id, __nome, __des, __ver) {memoriaOccupata=0;}
    
    ApplicazioneInstallata(long _id, const std::string &_nome, const std::string &_des, int _ver, long _mem) :                                          Applicazione(_id, _nome, _des, _ver) {memoriaOccupata=_mem;}
    
    void setMemoriaOccupata (long _mem) {memoriaOccupata=_mem;}
};
#endif