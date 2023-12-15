#ifndef KORTHAND_H
#define KORTHAND_H
#include "kort.h"
#include <vector>

class Korthand
{
public:
    Korthand();
    void rensa();
    int antalKort() const;
    Kort kort(int nr) const;
    void stoppaInKort(const Kort &kort);
    int poang() const;
private:
    std::vector<Kort>m_korten;
};

#endif // KORTHAND_H
