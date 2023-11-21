#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H
#include <string>

using namespace std;

class Transazione {
    private:
        string from;
        string to;
        float qt;
    public:
        Transazione(string from, string to, float qt):from(from),to(to),qt(qt){}
        ~Transazione();

    //setter
    void setFrom(string from){this->from = from;}
    void setTo(string to){this->to = to;}
    void setQt(float qt){this->qt = qt;}

    //getter
    string getFrom(){return from;}
    string getTo(){return to;}
    float getQt(){return qt;}

    void getInfoTx();
};

Transazione::~Transazione(){
    
}

void Transazione::getInfoTx(){
    cout << endl;
    cout << "From: " << from << endl;
    cout << "To: " << to << endl;
    cout << "Qt: " << qt << endl;
}

#endif // TRANSAZIONE_H