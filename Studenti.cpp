#include"Studenti.h"

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

#include<string>
using std::string;

Studente::Studente (string _nome,string _cognome,string _datanascita, long _matricola) : matricola(_matricola)
{   //la funzione può essere chiamata solo dentro il corpo del costruttore
    set(_nome, _cognome, _datanascita);
 }

Studente::Studente() : Studente ("---","---","---", 0) {}

Studente& Studente::set (string _nome,string _cognome,string _datanascita) {
    setNome(_nome);
    setCognome(_cognome);
    setDatanascita(_datanascita);
    //setMatricola(_matricola);

    return *this;
}

void Studente::setNome (string _nome) {
    nome=_nome;
}

void Studente::setCognome (string _cognome) {
    cognome=_cognome;
}

void Studente::setDatanascita (string _datanascita) {
    datanascita=_datanascita;
}

string Studente::getNome () const {return nome;}
string Studente::getCognome () const {return cognome;};
string Studente::getDatanascita () const {return datanascita;};
long Studente::getMatricola () const {return matricola;};

const Studente& Studente::get () const {
    getNome();
    getCognome();
    getDatanascita();
    getMatricola ();

    return *this;
}


ostream& Studente::print (ostream &os) {
    os << "Nome : " << getNome() << endl;
    os << "Cognome : " << getCognome() << endl;
    os << "Data di Nascita : " << getDatanascita() << endl;
    os << "Matricola :  0" << getMatricola() << endl;

}
