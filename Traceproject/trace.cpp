#include "trace.h"
#include <iostream>
#include <QDebug>

using namespace std;


static Trace::Outputtype UTSKRIFTSMETOD = Trace::output_qdebug;
static int AKTUELLT_DJUP = 0;

//qDebug() << str.c_str();

void Trace::printline(const std::string &str){
    if(UTSKRIFTSMETOD == output_cout)
        cout << str << endl;
    else qDebug() << str.c_str();
}

string Trace::indentering(){
    return string(3 * AKTUELLT_DJUP, ' ');
}
void Trace::message(const std::string &str){
    printline(indentering() + "trace:" +str);
}
Trace::Trace(const std::string& funktionsnamn){
    m_funktionsnamn = funktionsnamn;
    printline(indentering() + ">>" + m_funktionsnamn + ">>");
    AKTUELLT_DJUP +=1;
}

Trace::Trace(const std::string& funktionsnamn, const std::string& extra){
    m_funktionsnamn = funktionsnamn;
    printline(indentering() + ">>" + m_funktionsnamn + ">> "+ extra);
    AKTUELLT_DJUP +=1;
}

Trace::~Trace(){
    AKTUELLT_DJUP -=1;
    printline(indentering() + "<<" + m_funktionsnamn + "<<");
}
