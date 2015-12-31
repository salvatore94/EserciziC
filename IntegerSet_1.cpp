class IntegerSet_1 {
	int size;
	int *dataPtr;


public:
	IntegerSet_1 () : IntegerSet_1(1) {};
	IntegerSet_1 (int);
	~IntegerSet_1() {delete[] dataPtr;}

	void setSize (int);
	void setData (int, int);  
	const int& getSize () const {return size;}
	const int& getData (int pos) const {return dataPtr[pos];}
};


void IntegerSet_1::setData (int data, int pos) {
	if (pos >=0)
	if(data!= (this->getData(pos)))
		dataPtr[pos]=data;
}
void IntegerSet_1::setSize (int _size) {
	if (_size >= 0)
		if(size != _size)
			size=_size;
}

IntegerSet_1::IntegerSet_1 (int __size) {
	this -> setSize(__size):
	dataPtr = new long [this->getSize()];

	for(int i=0; i!= (this->getSize()); ++i)
		this->setData(0, i);
}