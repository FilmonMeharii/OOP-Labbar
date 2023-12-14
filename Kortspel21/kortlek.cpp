#include "kortlek.h"
#include "kort.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

Kortlek::Kortlek()
{

}

int Kortlek::antalKort() const
{
    return m_korten.size();
}

Kort Kortlek::utplockatKort()
{
    if(!m_korten.empty()){
        Kort kort = m_korten.back();
        m_korten.pop_back();
        return kort;
    }else {
        return Kort(Kort::klover, -1);
    }
}

void Kortlek::aterstallKortlek()
{
    m_korten.clear();
    for(int i=1; i<=52; i++){
        Kort::Farg farg = Kort::klover;
        int valor = (i % 13) +1;
        m_korten.push_back(Kort(farg,valor));
    }
}

void Kortlek::blanda()
{
    static std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(m_korten.begin(),m_korten.end(),generator);
}

void Kortlek::aterstalBlandadKortlek()
{
    aterstallKortlek();
    blanda();
}
