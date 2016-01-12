#include <cstdlib>
#include <ctime>
#include <iostream>

#ifndef LABIRINTO
#define LABIRINTO
class Labirinto {
	bool tabella [11] [11];
	void setValue(int x, int y, bool value) {tabella[x][y]=value;}

public:
	Labirinto ();

	bool isPossible (int _x, int _y) { if (this->tabella[_x][_y]==1) return true; else return false; }
    bool isPossible (int _x, int _y) const { if (this->tabella[_x][_y]==1) return true; else return false; }
    
    void print () const;
};



Labirinto::Labirinto() {
    srand(unsigned (time(0)));
	for (int i=0; i<=11; ++i){
        for (int j=0; j<=11; ++j)
            this->setValue(i, j, rand()%5);
	}
}

void Labirinto::print() const {
    for(int i=0; i<=11; ++i)
        for (int j=0; j<=11; ++j){
          if (this->isPossible(i,j) == false)
              std::cout << "¶" ;
        else
            std::cout << " ";
          if(j==11)
            std::cout<<" "<< std::endl;
        }
}
#endif