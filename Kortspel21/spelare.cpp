#include "spelare.h"
#include "minafunktioner.h"
#include <string>
#include <iostream>

using namespace std;

Spelare::Spelare()
{

}

bool Spelare::villSpela()
{
    return boolFranAnvandare("Vill du ha nytt kort? (Ja/Nej): ");
}

bool Spelare::villHaKort()
{
    return (boolFranAnvandare("Vill du ha ett till kort? (Ja/Nej): "));
}

void Spelare::tagEmotKort(const Kort &kort)
{
    m_hand.stoppaInKort(kort);
    cout << "Du fick ett kort: " << kort.text()<<endl;
}

void Spelare::bankenTogKort(const Kort &kort) const
{
    cout << "Banken tog ett kort: "<< kort.text()<< endl;
}

void Spelare::kortlekenHarBlandats()
{
    cout << "Kortleken har blandats: "<< endl;
}

void Spelare::speletAvslutat(bool spelarenvann)
{
    if(spelarenvann){
        cout << "Grattis! Du vann!"<< endl;
    }else{
        cout << "Banken vann. Battre lycka till! "<< endl;
    }
}

const Korthand &Spelare::korthand()
{
    return m_hand;
}
