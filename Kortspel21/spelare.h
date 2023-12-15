#ifndef SPELARE_H
#define SPELARE_H
#include "kort.h"
#include "korthand.h"



class Spelare
{
public:
    Spelare();
    bool villSpela();
    bool villHaKort();
    void tagEmotKort(const Kort &kort);
    void bankenTogKort(const Kort &kort) const;
    void kortlekenHarBlandats();
    void speletAvslutat(bool spelarenvann);

    const Korthand& korthand();
private:
    Korthand m_hand;
};

#endif // SPELARE_H
