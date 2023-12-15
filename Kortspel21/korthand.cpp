#include "korthand.h"

Korthand::Korthand()
{

}

void Korthand::rensa()
{
    m_korten.clear();
}

int Korthand::antalKort() const
{
    return m_korten.size();
}

Kort Korthand::kort(int nr) const
{
    return m_korten[nr];
}

void Korthand::stoppaInKort(const Kort &kort)
{
   m_korten.push_back(kort);
}

int Korthand::poang() const
{
    int totalPoang = 0;
    int numEss =0;
    for(const Kort &k:m_korten){
        int kortVarde = k.valor();
        if(kortVarde == 1){
            numEss++;
            if(totalPoang + 14 <= 21){
                numEss +=14;
            }else{
                totalPoang +=1;
            }
        }else{
            totalPoang +=kortVarde;
        }
    }
    while (numEss > 1 && totalPoang>21) {
        totalPoang -=13;
        numEss -=1;
    }
    return totalPoang;

}
