#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;

#include"Studenti.cpp"


int main () {
    string n, c, dn;
    long mat;

    cout << "Inserire i dati" << endl
         <<"Nome: ";
         cin >> n;
         cout  << "\nCognome: ";
         cin >>c;
         cout << "\nData di Nascita: ";
         cin >> dn;
         cout << "\nMatricola: ";
         cin >> mat;



    Studente s1(n,c,dn,mat);
    cout << "Il nome è: " << s1.getNome()<< endl;

    cout << "I dati completi sono: " << endl << endl;
    s1.print(cout);

    return 0;
}
