class Pila {
    char dati [100];
    int posizione=0;
    //const char Null="\0";
    
public:
    bool vuoto() {if (dati[0]=='\0') return true;  return false;}
    bool pieno() {if (dati[100]=='\0') return true; return false;}

    void inserisci (char);
    void rimuovi (char&);
};

void Pila::inserisci(char c) {
    for (int i=0; i<100; ++i) {
        if (dati[i]=='\0')
        posizione=i;
    }
    dati[posizione]=c;
    dati[posizione + 1]='\0';

}

void Pila::rimuovi (char &c) {
    for (int i=0; i<100; ++i) {
        while (dati[i]==c){
        for(int j=i+1; j<100; ++j)
            dati[i]=dati[j];
        }
    }
}
