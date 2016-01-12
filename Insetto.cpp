#include "Insetto.h"


void Scarabeo::muovi() {
	if (this->getLuogo()->isPossible(this->getX(), this->getY()+1)) 			 //nord
					this->setY( y+1 );
	else if (this->getLuogo()->isPossible(this->getX()+1, this->getY())) 	 //est
				this->setX( x+1 );
	else if (this->getLuogo()->isPossible(this->getX(), this->getY()-1))      //sud
					this->setY( y-1 );
	else if (this->getLuogo()->isPossible(this->getX()-1, this->getY())) 	 //ovest
					this->setX( x-1 );
}

void Insetto::setX (int _x){
        x=_x;
}
void Insetto::setY (int _y){
        y=_y;
}


void Formica::muovi() {
	// x+1, y      se esce 1		se esce 0
	// x-1, y  	   se esce 0
	// x, y+1      se esce 1		se esce 1
	// x, y-1  	   se esce 0
	if (random() == 0)/*modifico la X*/ {
		if(random() == 0) {
			if (this->getLuogo()->isPossible(this->getX()-1, this->getY()))
				this->setX( x-1 );
			else 
				this->muovi();
		}
		
		if (random() == 1) { 
			if (this->getLuogo()->isPossible(this->getX()+1, this->getY()))
				this->setX( x+1 );
			else
				this->muovi();
		}
	} 
	else if (random() == 1) /*modifico la Y */ {
		if (random() == 0){
			if (random() == 0) { 
				if (this->getLuogo()->isPossible(this->getX(), this->getY()-1))
					this->setY( y-1 );
				else
					this->muovi();
			}
			if (random() == 1) { 
				if (this->getLuogo()->isPossible(this->getX(), this->getY()+1))
					this->setY( y+1 );
				else
					this->muovi();
			}
		}
	}
}

bool Ragno::isTheOnlyWay (const int last) const {
/* 
0  --> fermo
1 --> nord
2 --> est
3 -->ovest
4 --> sud
*/

	switch (last) {
		case 1: { //nord
			if (this->getLuogo()->isPossible(this->getX()-1, this->getY()))
				return false;
			else if (this->getLuogo()->isPossible(this->getX()+1, this->getY()))
				return false;
			else if (this->getLuogo()->isPossible(this->getX(), this->getY()-1))
				return false;
			else if (this->getLuogo()->isPossible(this->getX(), this->getY()+1))
				return true;
		}
		case 2: { //est
			if (this->getLuogo()->isPossible(this->getX(), this->getY()+1))
				return false;
			else if (this->getLuogo()->isPossible(this->getX(), this->getY()-1))
				return false;
			else if (this->getLuogo()->isPossible(this->getX()-1, this->getY()))
				return false;
			else if (this->getLuogo()->isPossible(this->getX()+1, this->getY()))
				return true;
		}
		case 3: { //ovest
			if (this->getLuogo()->isPossible(this->getX()+1, this->getY()))
				return false;
			else if (this->getLuogo()->isPossible(this->getX(), this->getY()+1))
				return false;
			else if (this->getLuogo()->isPossible(this->getX(), this->getY()-1))
				return false;
			else if (this->getLuogo()->isPossible(this->getX()-1, this->getY()))
				return true;
		}
		case 4: { //sud
			if (this->getLuogo()->isPossible(this->getX()-1, this->getY()))
				return false;
			else if (this->getLuogo()->isPossible(this->getX()+1, this->getY()))
				return false;
			else if (this->getLuogo()->isPossible(this->getX(), this->getY()+1))
				return false;
			else if (this->getLuogo()->isPossible(this->getX(), this->getY()-1))
				return true;
		}
	}

    return false;
}

void Ragno::muovi () {
	//partenza da fermo
	if (this->getLastMove() == 0){
			if (random() == 0)/*modifico la X*/ {
				if(random() == 0) {
					if (this->getLuogo()->isPossible(this->getX()-1, this->getY())) {
						this->setX( x-1 );
						this->setLastMove(3);}  //salvo la direzione (ovest)
					else 
						this->muovi();
				}
				
				if (random() == 1) { 
					if (this->getLuogo()->isPossible(this->getX()+1, this->getY())) {
						this->setX( x+1 );
						this->setLastMove(2);} //salvo la direzione (est)
					}
					else
						this->muovi();
				}
			 
			else if (random() == 1) /*modifico la Y */ {
				if (random() == 0){
					if (random() == 0) { 
						if (this->getLuogo()->isPossible(this->getX(), this->getY()-1)) {
							this->setY( y-1 ); 
							this->setLastMove(4);}		//salvo la posizione (sud)
						else
							this->muovi();
					}
					if (random() == 1) { 
						if (this->getLuogo()->isPossible(this->getX(), this->getY()+1)) {
							this->setY( y+1 );
							this->setLastMove (1);} // salvo la posizione (nord)
						}
						else
							this->muovi();
					}
				}
	}			
	//scorsa posizione nord
	if(this->getLastMove() == 1){
		if (isTheOnlyWay(1) == true) {
				this->setY( y+1 );
				this->setLastMove (1); // salvo la posizione (nord)
		}
		else {
			if (random() == 0)/*modifico la X*/ {
				if(random() == 0) {
					if (this->getLuogo()->isPossible(this->getX()-1, this->getY())) {
						this->setX( x-1 );
						this->setLastMove(3);}  //salvo la direzione (ovest)
					else 
						this->muovi();
				}
				
				if (random() == 1) { 
					if (this->getLuogo()->isPossible(this->getX()+1, this->getY())) {
						this->setX( x+1 );
						this->setLastMove(2);} //salvo la direzione (est)
					}
					else
						this->muovi();
				}
			 
			else if (random() == 1) /*modifico la Y */ {
				if (random() == 0){
					if (random() == 0) { 
						if (this->getLuogo()->isPossible(this->getX(), this->getY()-1)) {}
							this->setY( y-1 ); 
							this->setLastMove(4);}		//salvo la posizione (sud)
						else
							this->muovi();
					}
					if (random() == 1) 
							this->muovi();					
			}	

		} 
	}
	//scorsa posizione est
	if (this->getLastMove() == 2){
		if (isTheOnlyWay(2) == true) {
				this->setX( x+1 );
				this->setLastMove (2); // salvo la posizione (nord)
		}
		else {
			if (random() == 0)/*modifico la X*/ {
				if(random() == 0) {
					if (this->getLuogo()->isPossible(this->getX()-1, this->getY())) {
						this->setX( x-1 );
						this->setLastMove(3);}  //salvo la direzione (ovest)
					else 
						this->muovi();
				}
				
				if (random() == 1) { 
						this->muovi();
				}
			 
			else if (random() == 1) /*modifico la Y */ {
				if (random() == 0){
					if (random() == 0) { 
						if (this->getLuogo()->isPossible(this->getX(), this->getY()-1)) {
							this->setY( y-1 ); 
							this->setLastMove(4);}		//salvo la posizione (sud)
						else
							this->muovi();
					}
					if (random() == 1) { 
						if (this->getLuogo()->isPossible(this->getX(), this->getY()+1)) {
							this->setY( y+1 );
							this->setLastMove (1);} // salvo la posizione (nord)
						}
						else
							this->muovi();
					}
				}
			}
		}
	}
	// scorsa posizione ovest 
	if (this->getLastMove() == 3){
		if (isTheOnlyWay(3) == true) {
				this->setX( x-1 );
				this->setLastMove (3); // salvo la posizione (ovest)
		}
		else {
			if (random() == 0)/*modifico la X*/ {
				if(random() == 0) {
						this->muovi();
				}
				
				if (random() == 1) { 
					if (this->getLuogo()->isPossible(this->getX()+1, this->getY())) {
						this->setX( x+1 );
						this->setLastMove(2);} //salvo la direzione (est)
					
					else
						this->muovi();
				}
			 
			else if (random() == 1) /*modifico la Y */ {
				if (random() == 0){
					if (random() == 0) { 
						if (this->getLuogo()->isPossible(this->getX(), this->getY()-1)) {
							this->setY( y-1 ); 
							this->setLastMove(4);}		//salvo la posizione (sud)
						else
							this->muovi();
					}
					if (random() == 1) { 
						if (this->getLuogo()->isPossible(this->getX(), this->getY()+1)) {
							this->setY( y+1 );
							this->setLastMove (1);} // salvo la posizione (nord)
						}
						else
							this->muovi();
					}
				}
			}
		}
	}
	//scorsa posizione sud
	if (this->getLastMove() == 4) {
		if (isTheOnlyWay(4) == true) {
				this->setY( y-1 );
				this->setLastMove (4); // salvo la posizione (nord)
		}
		else {
			if (random() == 0)/*modifico la X*/ {
				if(random() == 0) {
					if (this->getLuogo()->isPossible(this->getX()-1, this->getY())) {
						this->setX( x-1 );
						this->setLastMove(3);}  //salvo la direzione (ovest)
					else 
						this->muovi();
				}
				
				if (random() == 1) { 
					if (this->getLuogo()->isPossible(this->getX()+1, this->getY())) {
						this->setX( x+1 );
						this->setLastMove(2);} //salvo la direzione (est)
					}
					else
						this->muovi();
				}
			 
			else if (random() == 1) /*modifico la Y */ {
				if (random() == 0){
					if (random() == 0) { 
							this->muovi();
					}
					if (random() == 1) { 
						if (this->getLuogo()->isPossible(this->getX(), this->getY()+1)) {
							this->setY( y+1 );
							this->setLastMove (1);} // salvo la posizione (nord)
						}
						else
							this->muovi();
					}
				}
		}
	}
} 