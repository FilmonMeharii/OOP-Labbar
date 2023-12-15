#include "kort.h"

Kort::Kort(Farg farg, int valor): m_farg(farg), m_valor(valor)
{

}

Kort::Farg Kort::farg() const
{
    return m_farg;
}

int Kort::valor() const
{
    return m_valor;
}

std::string Kort::text() const
{
    static const char* valornamn[14]{"finnsej", "ess", "tva","tre","fyra",
                                     "fem","sex","sju","atta","nio","tio",
                                     "knekt","dam","kung"};
    return fargstrang() + " "+ valornamn[m_valor];
}

std::string Kort::fargstrang() const
{
    switch (m_farg) {
    case klover:
        return "Klover";
    case ruter:
        return "Ruter";
    case hjarter:
        return "Hjarter";
    case spader:
        return "Spade";
    default:
        return "Okand farg";
    }
}
