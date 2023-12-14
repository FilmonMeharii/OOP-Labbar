#include "minafunktioner.h"

#include <iostream>

using namespace std;

bool boolFranAnvandare(const string &txt){
    cout <<txt<< "Vill du ha nytt kort? Ja/Nej: ";
    string svar;
    cin >> svar;
    if(svar=="ja"||"Ja"||"JA")
        return true;
    return false;
}
