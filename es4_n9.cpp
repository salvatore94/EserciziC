#include<iostream>
using std::cout;
using std::endl;

#define DEBUG
//#include"String.h"
#include"String.cpp"

int main () {
    char a[5]={'H', 'e', 'l', 'l', 'o'};
    String s1;
    String s2(a, 5);
    String s3(s2);
    char a1[]={'T', 'e', 's', 't', ' ', '\0'};
    String s4(a1);

    s1=s1;
    cout << s1.isEmpty() << endl;
    cout << "Lunghezza di s2 : " << s2.len() << endl;
    cout << "Contenuto di s2: " ;
        s2.print(cout);

    cout << "Lunghezza di s3 : " << s3.len() << endl;
    cout << "Contenuto di s3: " ;
        s3.print(cout);

    cout << "Lunghezza di s4 : " << s4.len() << endl;
    cout << "Contenuto di s4: " ;
        s4.print(cout);

    s2.append(s3);
    cout << "Nuova lunghezza di s2 : " << s2.len() << endl;
    cout << "Nuovo contenuto di s2: " ;
        s2.print(cout);

    return 0;
}
