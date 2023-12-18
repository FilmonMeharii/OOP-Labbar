#include <iostream>
#include "fordon.h"
#include "bil.h"
#include "cykel.h"

using namespace std;

void skrivUtInfo();
void akenRunda(Fordon &fordon){
    cout << "Aker en runda------------"<<endl;
    skrivUtInfo();
    fordon.korFrammat(2);
    fordon.indikeraKommandeSvang();
    fordon.svangHoger();
    fordon.korFrammat(1.5);
    fordon.pakallaUppmarksamhet();
    fordon.korFrammat(0.5);
    fordon.svangVanster();
    fordon.korFrammat(0.1);

    cout << "Avslutar ak."<<endl << endl;
}
void ingangTillTestaFordon(){
    Cykel cykel;
    Bil bil;

    Fordon& refTillCykel = cykel;
    Fordon& ettFordon = cykel;

    akenRunda(refTillCykel);
    akenRunda(ettFordon);

    akenRunda(bil);
    akenRunda(cykel);
}

int main()
{
    cout << "Hello World!" << endl;
    ingangTillTestaFordon();
    return 0;
}
