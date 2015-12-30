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
    //cout << y ;           //mi assicuro che il valore letto sia corretto
    leggi.close();
    scrivi.open("test.txt", ios::in|ios::binary|ios::end);
    scrivi.seekp(2*sizeof(char), ios_base::beg);        //con gli ostream si usa la seekp()
                                                // l'operatore << tratta i valori come se fossero char
    scrivi << (y^key) ;                          // questa istruzione ci porta quindi alla terza posizione
                                                 // ovviamente quando andiamo ad aprire con hexedit ogni char
                                                 // è composto da 1 byte
    scrivi.close(); 
    leggi.open("test.txt");
    leggi.seekg(2*sizeof(char));                //con gli istream si usa la seekg()
    
    char a;
    for (int i=0; i!= 2; ++i) {
    leggi.get(a);
    cout << a ;
    }
    cout << endl;
    leggi.close();
    return 0;
 }
