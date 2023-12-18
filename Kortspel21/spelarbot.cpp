#include "spelarbot.h"
#include <iostream>


using namespace std;

Spelarbot::Spelarbot():
    m_antalPartierAttSpela(10), m_antalSpeladeSpel(0), m_totalvinst(0.0)
{

}


bool Spelarbot::villSpela()
{
    if(m_antalPartierAttSpela)
        return false;
    return true;
}

bool Spelarbot::villHaKort()
{
    return korthand().poang()<14;
}

void Spelarbot::tagEmotKort(const Kort &kort)
{
    cout << "Du fick ett kort: " << kort.text()<<endl;
}

void Spelarbot::bankenTogKort(const Kort &kort) const
{
    cout << "Banken tog ett kort: "<< kort.text()<< endl;
}

void Spelarbot::kortlekenHarBlandats()
{
    cout << "Kortleken har blandats: "<< endl;
}

void Spelarbot::speletAvslutat(bool spelarenvann)
{
    m_antalSpeladeSpel++;
    if(m_antalSpeladeSpel==m_antalPartierAttSpela){
        cout << "Den totala vinsten ar " << m_totalvinst << endl;
    }

    if(spelarenvann){
        m_totalvinst +=1.0;
    }else{
        m_totalvinst -=1.0;
    }
}

const Korthand &Spelarbot::korthand()
{

}
