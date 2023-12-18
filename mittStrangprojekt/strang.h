#ifndef STRANG_H
#define STRANG_H

#include <iostream>

class Strang
{
public:
    ~Strang();
    Strang();
    Strang(const char *cstr);
    Strang(const Strang& otherString);
    Strang(Strang &&stringToMove);

    const Strang& operator=(const Strang& otherString);
    const Strang& operator=( Strang&& stringToMove);
    const Strang& operator+=(const Strang& otherString);

    bool operator==(const Strang& otherString) const;

    char& operator[](int ix);
    char operator[](int ix) const;

    int size() const;
    const char* c_str() const;

private:
    char* m_cstr;
    int m_size;
};

bool operator!=(const Strang& a, const Strang& b);

std::ostream& operator<<(std::ostream& out, Strang& str);

inline std::ostream& operator<<(std::ostream& out, Strang& str) {
    out << str.c_str();
    return out;
}


#endif // STRANG_H
