#ifndef BIL_H
#define BIL_H
#include "fordon.h"

class Bil : public Fordon
{
public:
    Bil();

    // Fordon interface
public:
    void pakallaUppmarksamhet() override;
    void indikeraKommandeSvang() override;
    void svangVanster() override;
    void svangHoger() override;
    void korFrammat(float antalKm) override;
};

#endif // BIL_H
