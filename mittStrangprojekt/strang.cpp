#include "strang.h"
#include <cstring>
#include <iostream>
#include <cassert>

using namespace std;
Strang::~Strang()
{
    delete [] m_cstr;
}
Strang::Strang():  m_cstr(new char[1]{'\0'}), m_size(0){}
Strang::Strang(const char* cstr){
    if(cstr == nullptr){
        m_cstr = new char[1]{'\0'};
        m_size = 0;
    }else{
        m_size = strlen(cstr);
        m_cstr = new char[m_size + 1];
        strcpy(m_cstr, cstr);
    }
}
Strang::Strang(const Strang& otherString) :Strang(otherString.c_str()){}
Strang::Strang(Strang &&stringToMove):m_cstr(stringToMove.m_cstr), m_size(stringToMove.m_size){
    stringToMove.m_cstr = nullptr;
    stringToMove.m_size = 0;
}

const Strang& Strang::operator=(const Strang& otherString) {
    if (this == &otherString) {
        return *this;
    }

    delete[] m_cstr;

    m_size = otherString.size();
    m_cstr = new char[m_size + 1];
    std::strcpy(m_cstr, otherString.c_str());

    return *this;
}

const Strang& Strang::operator=(Strang&& stringToMove) {
    if (this == &stringToMove) {
        return *this;
    }

    delete[] m_cstr;

    m_cstr = stringToMove.m_cstr;
    m_size = stringToMove.m_size;

    stringToMove.m_cstr = nullptr;
    stringToMove.m_size = 0;

    return *this;
}

const Strang& Strang::operator+=(const Strang& otherString) {
    int totalSize = m_size + otherString.size();
    char* newStr = new char[totalSize + 1];

    std::strcpy(newStr, m_cstr);
    std::strcat(newStr, otherString.c_str());

    delete[] m_cstr;
    m_cstr = newStr;
    m_size = totalSize;

    return *this;
}

bool Strang::operator==(const Strang& otherString) const {
    if (m_size != otherString.size()) {
        return false;
    }

    return std::strcmp(m_cstr, otherString.c_str()) == 0;
}

char& Strang::operator[](int ix) {
    if (ix >= 0 && ix < m_size) {
        return m_cstr[ix];
    }
    throw std::out_of_range("Index out of range");
}

char Strang::operator[](int ix) const {
    if (ix >= 0 && ix < m_size) {
        return m_cstr[ix];
    }
    throw std::out_of_range("Index out of range");
}

int Strang::size() const {
    return m_size;
}

const char* Strang::c_str() const {
    return m_cstr;
}

bool operator!=(const Strang& a, const Strang& b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream& out, const Strang& str) {
    out << str.c_str();
    return out;
}

Strang mittNamn(){
    return "Filmon";
}
void anropByValue(Strang str){
    cout << str << endl;
}
void anropByRef(const Strang &str){
    cout << str << endl;
}
bool arVersaler(const Strang &str){
    for (int i=0; i<str.size(); ++i)
        if (str[i] != toupper(str[i]))
            return false;
    return true;
}
void konverteraTillVersaler(Strang &str){
    for (int i=0; i<str.size(); ++i)
        str[i] = toupper(str[i]);
}
Strang versalstrang(const Strang &str){
    Strang kopia = str;
    konverteraTillVersaler( kopia );
    return kopia;
}
void testaStrang(){
    Strang str1;
    assert( str1 == "");
    Strang str2 = "Hej";
    assert( str2.size() == 3 );
    str2 = "Sol";
    assert( str2.size() == 3 );
    assert( str2[1] == 'o');
    str2 += "sken!";
    assert( str2.size() == 8 );
    assert( str2 == "Solsken!");
    Strang str3 = mittNamn();
    anropByValue(str3);
    anropByRef(str3);
    assert( !arVersaler(str2) );
    konverteraTillVersaler(str2);
    assert( arVersaler(str2) );
    Strang str4 = versalstrang( "hej" );
    assert( arVersaler(str4) );
    cout << "testaStrang lyckades" << endl;
}
