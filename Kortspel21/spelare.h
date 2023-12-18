#ifndef SPELARE_H
#define SPELARE_H

#include "kort.h"
#include "korthand.h"
#include "abstraktspelare.h"

class Spelare : public AbstraktSpelare
{
public:
    Spelare();
    bool villSpela() override;
    bool villHaKort() override;
    void tagEmotKort(const Kort &kort) override;
    void bankenTogKort(const Kort &kort) const override;
    void kortlekenHarBlandats() override;
    void speletAvslutat(bool spelarenvann) override;

    const Korthand& korthand() override;
private:
    Korthand m_hand;
};

#endif // SPELARE_H
