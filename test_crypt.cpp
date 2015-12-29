#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include<fstream>
using std::ofstream;
using std::ios;

int main() {

    int x;
    cout << "Inserire valore: "  << endl;
    cin >> x;

    // 46= 00101110
    int key=46;
    int altered= x^key;
    cout << "Valore alterato: " <<  altered << endl;

    cout << "Valore originario: " << (altered^key) << endl;

    // ofstream scrivi("test.txt", ios::binary);
    // scrivi << altered<< endl;
    //
    // scrivi.close();
    // int y=0;
    // ofstream leggi("test.txt", ios::in|ios::binary);
    // //while (leggi!= 0x0A)
    //     cout << "Valore decifrato: " << (leggi^key) << endl;
    return 0;
 }
