#include "minafunktioner.h"

#include <iostream>

using namespace std;

bool boolFranAnvandare(const string &txt){
    cout <<txt;
    string svar;
    cin >> svar;
    if(svar=="ja"|| svar=="Ja"|| svar =="JA" || svar =="j")
        return true;
    return false;
}
