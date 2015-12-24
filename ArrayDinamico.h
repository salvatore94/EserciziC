#ifndef ARRAYDINAMICO_H
#define ARRAYDINAMICO_H
#include <iostream>

class ArrayDinamico {
    int dimensione;
    int* data;

public:
    ArrayDinamico () : ArrayDinamico(10) {};
    ArrayDinamico (int);

    ~ArrayDinamico () {delete[] data; std::cout << "Il distruttore è stato invocato" << std::endl;};
    ArrayDinamico& operator= (const ArrayDinamico&);

    int getDimValue () const {return dimensione;};
    int getDataValue (int pos) const {return data[pos];};

    void resize (int);
    int& at (int pos) {return *(data+pos);};
};

#endif
