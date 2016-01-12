#include <cstdlib>
#include <ctime>
#include <string>
#include "Labirinto.cpp"
#ifndef INSETTO
#define INSETTO
class Insetto {
	const std::string id;

	Labirinto* luogo;
protected:
    int x, y;
public:
    Insetto (const std::string &_id, Labirinto *ptr) : id(_id), luogo(ptr) {};
	void virtual muovi ()=0;
    

	void setX (int _x);
	void setY (int _y);

    bool isOut () { if (this->getX()<0 || this->getX()>11 || this->getY()<0 || this->getY()>11) return true; else return false;}
    
	int getX () const {return x;}
	int getY () const {return y;}
    const std::string & getId () const {return id;}
    //Labirinto* getLuogo()  {return luogo;}
    const Labirinto* getLuogo() const  {return luogo;}
};
int randomPos () {
	srand(unsigned (time(0)));
	return rand()%2;
}		//restituisce o 0 oppure 1


class Formica : public Insetto {
public:
    Formica (const std::string &_id, Labirinto *ptr): Insetto(_id, ptr) {};
	void muovi();
};

class Scarabeo: public Insetto {
public:
    Scarabeo (const std::string &_id, Labirinto *ptr): Insetto(_id, ptr) {};
	void muovi();
};

class Ragno: public Insetto {
	short lastMove;
public:
	Ragno (const std::string &_id, Labirinto *ptr) : Insetto(_id, ptr), lastMove(0) {};
	short getLastMove() const {return lastMove;}
	void setLastMove(int _new) {if (_new >0 && _new<5 && _new!= this->getLastMove()) lastMove=_new;}
    bool isTheOnlyWay (const int) const ;
	void muovi();
};

#endif