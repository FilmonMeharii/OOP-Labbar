#ifndef BANKIR_H
#define BANKIR_H
#include "spelare.h"
#include "kortlek.h"



class Bankir
{
public:
    Bankir();
    void registreraSpelare(AbstraktSpelare *pSpelare);
    bool harRegistreradeSpelare() const;
    void spelaEnOmgang();
private:
    Kortlek m_kortlek;
    AbstraktSpelare *m_pSpelare;
};

#endif // BANKIR_H
