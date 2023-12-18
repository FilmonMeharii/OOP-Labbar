#ifndef TRACE_H
#define TRACE_H
#include <string>
#include <iostream>
#include <QDebug>

#define traceme Trace traceObject(__func__);
#define tracemex(extra) Trace traceObject(__func__, extra);
#define tracemsg(meddelande) traceObject.message(meddelande);

class Trace
{
public:
    enum Outputtype{output_cout, output_qdebug};
    Trace(const std::string& funktionsnamn);
    Trace(const std::string& funktionsnamn, const std::string& extra);
    ~Trace();

    void message(const std::string& str){
        printline(indentering()+ "trace: " + str);
    }

    static int s_aktuelltDjup;
    static Outputtype s_utskriftsMetod;

private:
    std::string m_funktionsnamn;
    std::string indentering();
    void printline(const std::string& str) {
            if (s_utskriftsMetod == output_cout)
                std::cout << str << std::endl;
            else
                qDebug() << str.c_str();
        }};

inline Trace::Trace(const std::string& funktionsnamn) {
    m_funktionsnamn = funktionsnamn;
    printline(indentering() + ">>" + m_funktionsnamn + ">>");
    s_aktuelltDjup += 1;
}

inline Trace::Trace(const std::string& funktionsnamn, const std::string& extra) {
    m_funktionsnamn = funktionsnamn;
    printline(indentering() + ">>" + m_funktionsnamn + ">> " + extra);
    s_aktuelltDjup += 1;
}

inline Trace::~Trace() {
    s_aktuelltDjup -= 1;
    printline(indentering() + "<<" + m_funktionsnamn + "<<");
}


inline std::string Trace::indentering() {
    return std::string(3 * s_aktuelltDjup, ' ');
}

#endif // TRACE_H
