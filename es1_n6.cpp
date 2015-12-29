#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;

#include<fstream>
using std::ofstream;
using std::ios;

#include"Persona.cpp"

int main () {
    Persona p1("salvo", "polito", "licata");
    Persona p2("tizio", "caio", "---");

    ofstream scrivi("prova.txt");

    scrivi << p1.getNome() << endl
        <<p1.getCognome() << endl
        <<p1.getIndirizzo()  << endl;


    scrivi.close();


    scrivi.open("prova.txt", ios::in|ios::end);

    scrivi << p2.getNome() << endl
        <<p2.getCognome() << endl
        <<p2.getIndirizzo()  << endl;


    scrivi.close();

    return 0;
}
