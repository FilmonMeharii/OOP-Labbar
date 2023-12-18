#ifndef FORDON_H
#define FORDON_H


class Fordon
{
public:
    Fordon(int antalHjul);
    virtual void pakallaUppmarksamhet();
    virtual void indikeraKommandeSvang();
    virtual void svangVanster();
    virtual void svangHoger();
    virtual void korFrammat(float antalKm);

private:
    int m_antalHjul;
};

#endif // FORDON_H
