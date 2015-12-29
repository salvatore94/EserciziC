#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include<fstream>
using std::ofstream;
using std::ifstream;
using std::ios;
using std::ios_base;

int main() {

    int x;
    cout << "Inserire valore: "  << endl;
    cin >> x;

    // 46= 00101110
    int key=46;
    int altered= x^key;
    cout << "Valore alterato: " <<  altered << endl;

    //cout << "Valore originario: " << (altered^key) << endl;

    ofstream scrivi("test.txt", ios::binary);
    scrivi << altered<< endl;

    scrivi.close();
    ifstream leggi("test.txt", ios::binary);
    
    int y;
    leggi >> y;
    //cout << y ;

    scrivi.open("test.txt", ios::in|ios::binary|ios::end);
    scrivi.seekp(2*sizeof(char), ios_base::beg); // l'operatore << tratta i valori come se fossero char
    scrivi << (y^key) ;                       //  questa istruzione ci porta quindi alla terza posizione
                                            // ovviamente quando andiamo ad aprire con hexedit ogni char è composto di 1 byte
    scrivi.close();
    return 0;
 }
