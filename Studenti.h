#ifndef STUDENTI_H
#define STUDENTI_H

class Studente {
    std::string nome;
    std::string cognome;
    std::string datanascita;

    const long matricola;

    //metodi set per i singoli membri
    //intendo usarli per la convalitda dei dati
    void setNome (std::string);
    void setCognome (std::string);
    void setDatanascita (std::string);
    //utilizzando un const long non posso più assegnare a matricola
    //void setMatricola (long);

public:

    Studente();
    Studente (std::string,std::string,std::string,long);


    //il metodo set voglio che vada a richiamare i singoli
    //set per convalidare i dati
    Studente& set (std::string,std::string,std::string);

    //metodi get
    std::string getNome () const;
    std::string getCognome () const;
    std::string getDatanascita () const;
    long getMatricola () const;

    const Studente& get () const;

    //il metodo print riceve e restituisce un ostream
    //utilizzerà le funzioni get
    std::ostream& print (std::ostream&);

};

#endif
