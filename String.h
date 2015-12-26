#ifndef STRING_H
#define STRING_H

#include<iostream>

class String {
    //I dati verranno salvati all'interno di un array salvato in memoria dinamica,
    //la dimensione della stringa sarà size
    //fornirò un metodo che effettua la conversione a string-c
    char *data;
    int size;

public:
    String(); //Di default genera una stringa vuota
    String(char [], int);
    String(const String&); //copy constructor
    String(char *); //Costruttore per creare una stringa a partire da una stringaC

    ~String();

    String& operator= (const String&);

    const int len() const {return size;}
    bool isEmpty() const;
    int compare(const String&) const;  //restituisce 0 se sono della stessa lunghezza, +1 se s1>s2 e -1 se s1<s2
    void setSize (int _size) {if(_size >= 0) size=_size;}

    String& append (const String&);
    char* convertToC_String () const;
    void print(std::ostream&);
};
#endif
