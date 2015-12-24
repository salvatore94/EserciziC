#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;

#include "Appuntamenti.cpp"
#include "Agenda.cpp"


int main () {

    int h=15, m=43, s=10;
    Time t1(h,m,s);
    cout << "I dati inseriti per t1 sono: " <<endl
        << "h=" << h << endl
        << "m=" << m << endl
        << "s=" << s << endl << endl;
    cout << "L'oggetto t1 associato è: " << endl
         << t1.getOra() << ":" << t1.getMinuti() << ":" << t1.getSecondi ()<<endl;

    int h1=19, m1=10, s1=6;
    Time t2(h1,m1,s1);
        cout << "I dati inseriti per t2 sono: " <<endl
            << "h=" << h1 << endl
            << "m=" << m1 << endl
            << "s=" << s1 << endl << endl;
        cout << "L'oggetto t1 associato è: " << endl
         << t2.getOra() << ":" << t2.getMinuti() << ":" << t2.getSecondi () <<endl;

    string ss="Test1";

    Appuntamenti a(t1, t2, ss);

    cout << "Test appuntamento" << endl;
         a.print(cout);
    cout << "\nDurata: " <<a.durata() << endl;

    cout <<"Inserisco l'appuntamento dentro un'agenda: "<< endl;
    Agenda es1;

    es1.getAppuntamento(0).print(cout);
    es1.aggiungi(a);
    es1.getAppuntamento(1).print(cout);
    Agenda es2(a);
    es2.getAppuntamento(0).print(cout);
    es1.cerca(t2);
    return 0;
}
