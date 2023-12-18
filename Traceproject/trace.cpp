#include "trace.h"
#include <iostream>
#include <QDebug>

using namespace std;


int Trace::s_aktuelltDjup = 0;
Trace::Outputtype Trace::s_utskriftsMetod= Trace::output_qdebug;

void Trace::printline(const std::string &str){
    if(s_utskriftsMetod == output_cout)
        cout << str << endl;
    else qDebug() << str.c_str();
}

string Trace::indentering(){
    return string(3 * s_aktuelltDjup, ' ');
}
void Trace::message(const std::string &str){
    printline(indentering() + "trace:" +str);
}
Trace::Trace(const std::string& funktionsnamn){
    m_funktionsnamn = funktionsnamn;
    printline(indentering() + ">>" + m_funktionsnamn + ">>");
    s_aktuelltDjup +=1;
}

Trace::Trace(const std::string& funktionsnamn, const std::string& extra){
    m_funktionsnamn = funktionsnamn;
    printline(indentering() + ">>" + m_funktionsnamn + ">> "+ extra);
    s_aktuelltDjup +=1;
}

Trace::~Trace(){
    s_aktuelltDjup -=1;
    printline(indentering() + "<<" + m_funktionsnamn + "<<");
}
