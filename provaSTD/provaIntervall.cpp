#include <iostream>
#include "intervall.h"

using namespace std;

void provIntervall(){
    cout <<"Loopar nagra varv"<<endl;

    Intervall talomrade(10,20);
    for(Intervall::iterator ite =talomrade.begin(); ite!=talomrade.end(); ++ite)
        cout <<*ite<<endl;
    cout << "Loopar igen"<<endl;

    for(Intervall::iterator ite=begin(talomrade); ite!=end(talomrade); ++ite)
        cout <<*ite<<endl;
    cout << "Loopar lite mera"<<endl;

    for(int tal: talomrade)
        cout << tal <<endl;

    cout <<"Loopar annu lite mera "<<endl;

    for(int tal :Intervall(10,20))
        cout <<tal<<endl;
}
