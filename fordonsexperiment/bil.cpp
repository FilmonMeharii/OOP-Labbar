#include "bil.h"
#include <iostream>

using namespace std;

Bil::Bil(): Fordon(4){}


void Bil::pakallaUppmarksamhet()
{
    cout << "Tut Tut Tut"<<endl;
}

void Bil::indikeraKommandeSvang()
{
    cout << "Bil: Blink blink"<<endl;
}

void Bil::svangVanster()
{
    cout << "Bilen: svanger vanster"<<endl;
}

void Bil::svangHoger()
{
    cout << "Bilen: svanger hoger"<<endl;
}

void Bil::korFrammat(float antalKm)
{
    cout << "Bilen: kor framot "<< antalKm<< " km "<<endl;

}

void Bil::skrivUtInfo()
{
    cout << "Fordonet ar en bil"<<endl;
    Super::skrivUtInfo();
}
