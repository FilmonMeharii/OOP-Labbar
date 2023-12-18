#include "cykel.h"
#include <iostream>

using namespace std;

Cykel::Cykel() : Fordon(2) {}

void Cykel::pakallaUppmarksamhet()
{
    cout << "Cykeln: pling pling"<<endl;
}

void Cykel::indikeraKommandeSvang()
{
    cout << "Cykeln: viftar at vanster eller hoger"<<endl;
}

void Cykel::svangVanster()
{
    cout << "Cykeln: viftar at vanster"<<endl;
}

void Cykel::svangHoger()
{
    cout << "Cykeln: viftar at hoger"<<endl;
}

void Cykel::korFrammat(float antalKm)
{
    cout << "Cykeln: trampa framot " << antalKm << " km"<<endl;
}
