#include <typeinfo>
#include <iostream>

using namespace std;
class Bas{
public:
    void iv(){cout << "Bas iv() anropades. "<<endl;}
    virtual void v() {cout << "Base v() anropades. "<<endl;}
    virtual ~Bas(){cout << "Bas destruktor" << endl;}
};

class Sub :public Bas{
public:
    void iv(){cout << "Sub iv() anropades. " << endl;}
    void v() {cout << "Sub v() anropades. "<< endl;}
    ~Sub() { cout << "Sub destruktor" << endl;}
};

void eperimentMedVirtual(){
    cout << endl << "Test1, anrop via sub "<<endl;
    Sub sub;
    sub.iv();
    sub.v();

    cout << endl<< "Test2, anrop via bas1" << endl;
    Bas bas1 = sub;
    bas1.iv();
    bas1.v();

    cout <<endl<< "Test3, anrop via bas-pekare" <<endl;
    Bas *pB = &sub;
    pB->iv();
    pB->v();
    (*pB).iv();
    (*pB).v();

    cout << endl <<"Test4, anrop via basreferens"<<endl;
    Bas &bas2 = sub;
    bas2.iv();
    bas2.v();
    cout << endl << "testaVirtual avslutas"<<endl;
}
void eperimentMedDestruktor(){
    cout << endl << "Testar destruktor" << endl;
    Bas* pBase = new Sub;
    delete pBase;
}

void provaDownCasting(Bas *pBas){
    Sub *pSub = dynamic_cast<Sub*>(pBas);
    if(pSub != nullptr)
        cout << "yes, vi har fatt en pekare till ett subklassobjekt!" << endl;
    else cout <<"Nope, typomvandlingen gick ej!"<<endl;
}
void eperimentMedDynamicDownCasting(){
    cout << "experiment med dynamic down casting"<< endl;
    Bas *pX = new Bas;
    Bas *pY = new Sub;

    provaDownCasting(pX);
    provaDownCasting(pY);

    delete pX;
    delete pY;
}

int main()
{
    cout << "Hello World!" << endl;
    eperimentMedVirtual();
    eperimentMedDestruktor();
    eperimentMedDynamicDownCasting();
    return 0;
}
