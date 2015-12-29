#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include<fstream>
using std::ofstream;
using std::ifstream;
using std::ios;

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
    scrivi << (y^key) ;

    scrivi.close();
    return 0;
 }
