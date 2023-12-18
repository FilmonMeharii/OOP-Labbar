#include "fordon.h"
#include <iostream>

using namespace std;

Fordon::Fordon(int antalHjul):m_antalHjul(antalHjul){ }

void Fordon::skrivUtInfo()
{
    cout << "Ett fordon med  " << m_antalHjul<< " hjul. "<<endl;
}
