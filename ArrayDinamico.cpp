#include"ArrayDinamico.h"


ArrayDinamico::ArrayDinamico (int dim) {
    dimensione=dim;
    data= new int[dimensione];

    for(int i=0; i<= dimensione; ++i)
        data[i]=0;
}

ArrayDinamico::ArrayDinamico (const ArrayDinamico &tocopy) : dimensione(tocopy.getDimValue()){
    data=new int[dimensione];
    std::cout << "Costruttore di copia Invocato" << std::endl;
    for(int i=0; i<= dimensione; ++i)
        this->at(i)=tocopy.getDataValue(i);
}


void ArrayDinamico::resize (int dim) {
    ArrayDinamico temp(dim);
    for (int i=0; i<=(this->getDimValue()); ++i)
        temp.at(i)=(this->getDataValue(i));

    (*this)=temp;
}

ArrayDinamico& ArrayDinamico::operator= (const ArrayDinamico &secondo) {
    if(data==secondo.data) {
        std::cout << "Assegnazione di due oggetti identici rilevata" << std::endl;
        return *this;
    }
    
    dimensione=secondo.getDimValue();
    delete [] data;
    data = new int[dimensione];
    for(int i=0; i<=(this->getDimValue()); ++i)
        data[i]=secondo.getDataValue(i);
        //this->at(i)=secondo.getVal(i);

    return *this;
}
