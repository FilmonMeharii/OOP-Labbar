#ifndef ABSTRAKTSPELARE_H
#define ABSTRAKTSPELARE_H
#include "kort.h"
#include "korthand.h"

class AbstraktSpelare
{
public:
   AbstraktSpelare();

    virtual bool villSpela() = 0;
   virtual bool villHaKort() = 0;
    virtual void tagEmotKort(const Kort &kort)=0;
    virtual void bankenTogKort(const Kort &kort) const=0;
    virtual void kortlekenHarBlandats()=0;
    virtual void speletAvslutat(bool spelarenvann)=0;

    virtual const Korthand& korthand()=0;
};

#endif // ABSTRAKTSPELARE_H
