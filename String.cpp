#include"String.h"

String::String () {
    this->setSize(0);
    // data=new char[0];
    data=nullptr;
}

String::String (char _data[], int _size) {
    this->setSize(_size);
    data = new char[size];

    for(int i=0; i!=size; ++i)
        data[i]= _data[i];
}

String::~String() {
    delete[] data;
    #ifdef DEBUG
    std::cout << "Distruttore invocato" << std::endl;
    #endif
}

String::String(char *_data){
    int count=0;
    for(int i=0; _data[i]!='\0'; ++i)
        ++count;
    this->setSize(count);
    data= new char[this->len()];

    for(int i=0; i!=(this->len()); ++i)
        data[i]= _data[i];
}

String& String::operator= (const String &tocopy) {
    if(data==tocopy.data){
        #ifdef DEBUG
        std::cout << "Assegnamento dello stesso oggetto!" << std::endl;
        #endif
        return *this;
    }
    this->setSize(tocopy.len());

    delete[] data;
    data= new char[this->len()];

    for(int i=0; i!=this->len(); ++i)
        data[i]=tocopy.data[i];

    return *this;
}

String::String (const String &tocopy) {
    this->setSize(tocopy.len());
    data=new char[this->len()];

    (*this)=tocopy;
    #ifdef DEBUG
    std::cout << "Copy constructor invocato" << std::endl;
    #endif
}

bool String::isEmpty () const {
    if(this->len()==0)
        return true;
    return false;
}

char* String::convertToC_String () const {
    char *temp = new char[this->len() + 1];
    for(int i=0; i!=this->len(); ++i)
        temp[i]=data[i];
    temp[this->len() + 1] = '\0';

    #ifdef DEBUG
    std::cout << "ConvertToC_String invocato" << std::endl;
    #endif
    return temp;
}

std::ostream& String::print (std::ostream &os) {
    for(int i=0; i!=this->len(); ++i)
        os << data[i];
    os << std::endl;
    return os;
}

String& String::append (const String &toappend) {
    String temp;
    temp.setSize(this->len() + toappend.len());

    delete[] temp.data;
    temp.data=new char[temp.len()];

    for(int i=0; i!=this->len(); ++i)
        temp.data[i]=data[i];
    for(int i=0; i!=toappend.len(); ++i)
        temp.data[this->len()+i]=toappend.data[i];

    (*this)=temp;
    return *this;
}

int String::compare(const String &s2) const {
    if(this->len()>s2.len())
        return 1;
    else if(this->len()==s2.len())
        return 0;
    else
        return -1;
}
