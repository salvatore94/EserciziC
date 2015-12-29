#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {

    int x;
    cout << "Inserire valore: "  << endl;
    cin >> x;

    // 46= 00101110
    int key=46;
    int altered= x^key;
    cout << "Valore alterato: " <<  altered << endl;

    cout << "Valore originario: " << (altered^key) << endl;

    return 0;
 }
