#include "komplex.h"
#include <cmath>
#include <cassert>
#include <iostream>

using namespace std;


Komplex::Komplex():m_re(0.0), m_im(0.0){}
Komplex::Komplex(float re, float im):m_re(re), m_im(im){}
Komplex Komplex::fromAbsArg(float a, float grader){
    float radianer = grader * M_PI / 180.0;
    return Komplex(a* cos(radianer), a*sin(radianer));
}

float Komplex::re() const{return m_re;}
float Komplex::im() const{return m_im;}
float Komplex::abs() const{return std::sqrt(m_re * m_re + m_im*m_im);}
float Komplex::argRadians() const{return std::atan2(m_im, m_re);}
float Komplex::argDegrees() const{return argRadians()* 180.0 /M_PI;}

Komplex Komplex::konjugat() const{return Komplex(m_re, -m_im);}
Komplex::operator std::string()const{return "(" + std::to_string(m_re) +  " +" + std::to_string(m_im) + "i)";}

const Komplex& Komplex::operator+=(const Komplex& h) {
    m_re += h.m_re;
    m_im += h.m_im;
    return *this;
}
const Komplex& Komplex::operator-=(const Komplex& h) {
    m_re -= h.m_re;
    m_im -= h.m_im;
    return *this;
}
const Komplex& Komplex::operator*=(const Komplex& h) {
    float new_re = m_re * h.m_re - m_im * h.m_im;
    float new_im = m_re * h.m_im + m_im * h.m_re;
    m_re = new_re;
    m_im = new_im;
    return *this;
}
const Komplex& Komplex::operator/=(const Komplex& h) {
    float denom = h.m_re * h.m_re + h.m_im * h.m_im;
    float new_re = (m_re * h.m_re + m_im * h.m_im) / denom;
    float new_im = (m_im * h.m_re - m_re * h.m_im) / denom;
    m_re = new_re;
    m_im = new_im;
    return *this;
}

Komplex operator "" _i( unsigned long long i) {
    return Komplex(0, static_cast<float>(i));
}
Komplex operator+(const Komplex& v, const Komplex& h) {
    return Komplex(v) += h;
}
Komplex operator-(const Komplex& v, const Komplex& h) {
    return Komplex(v) -= h;
}
Komplex operator*(const Komplex& v, const Komplex& h) {
    return Komplex(v) *= h;
}
Komplex operator/(const Komplex& v, const Komplex& h) {
    return Komplex(v) /= h;
}
std::ostream& operator<<(std::ostream& out, const Komplex& c) {
    out << std::string(c);
    return out;
}

void assertApprox(Komplex c1, Komplex c2){
    Komplex diff = c1-c2;
    assert(diff.abs()<0.001);
}
void testKod(){
    Komplex c1 = 1 + 3.0_i;
    Komplex c2 = 5 - 5_i;

    assertApprox(c1 + c2, Komplex(6-2));
    assertApprox(c1, (c1*c2)/c2);

    assertApprox(2*c1, Komplex(2,6));
    assertApprox(c1*2, Komplex(2,6));

    Komplex k=1;
    Komplex rotate30 = Komplex::fromAbsArg(1, 30);
    for(int i =0; i<12; ++i){
        k *= rotate30;
        cout << i << '\t' << k << endl;
    }
}

int main()
{
    cout << "Hello World!" << endl;
    testKod();
    return 0;
}
