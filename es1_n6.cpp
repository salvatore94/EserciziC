#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;

#include<fstream>
using std::ofstream;

#include"Persona.cpp"

int main () {
    Persona p1("salvo", "polito", "licata");

    ofstream scrivi("prova.txt");
    scrivi << p1.getNome() << endl
        <<p1.getCognome() << endl
        <<p1.getIndirizzo() << endl;

    scrivi.close();
    return 0;
}
