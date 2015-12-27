class Persona {
    std::string nome;
    std::string cognome;
    std::string indirizzo;

public:
    Persona() : Persona("---","---","---") {};
    Persona(const string&, const string&, const string &);

    Persona& setNome (const std::string&);
    Persona& setCognome (const std::string&);
    Persona& setIndirizzo (const std::string&);

    const std::string& getNome () const {return nome;}
    const std::string& getCognome () const {return cognome;}
    const std::string& getIndirizzo () const {return indirizzo;}
};

Persona::Persona(const string &_n, const string &_c, const string &_i) {
    this->setNome(_n);
    this->setCognome(_c);
    this->setIndirizzo(_i);
}

Persona& Persona::setNome (const std::string &_nome) {
    if (_nome.empty())
        return *this;
    if (this->getNome()==_nome)
        return *this;
    nome=_nome;
    return *this;
}

Persona& Persona::setCognome (const std::string &_cognome) {
    if (_cognome.empty())
        return *this;
    if (this->getCognome()==_cognome)
        return *this;
    cognome=_cognome;
    return *this;
}

Persona& Persona::setIndirizzo (const std::string &_indirizzo) {
    if (_indirizzo.empty())
        return *this;
    if (this->getIndirizzo()==_indirizzo)
        return *this;
    indirizzo=_indirizzo;
    return *this;
}
