#ifndef SPELARBOT_H
#define SPELARBOT_H
#include "abstraktspelare.h"

class Spelarbot:public AbstraktSpelare
{
public:
    Spelarbot();

    // AbstraktSpelare interface
    bool villSpela() override;
    bool villHaKort() override;
    void tagEmotKort(const Kort &kort) override;
    void bankenTogKort(const Kort &kort) const override;
    void kortlekenHarBlandats() override;
    void speletAvslutat(bool spelarenvann) override;
    const Korthand &korthand() override;
private:
    int m_antalPartierAttSpela;
    int m_antalSpeladeSpel;
    float m_totalvinst;


};

#endif // SPELARBOT_H
