#ifndef TRACE_H
#define TRACE_H
#include <string>

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

    void message(const std::string& str);

    static int s_aktuelltDjup;
    static Outputtype s_utskriftsMetod;

private:
    std::string m_funktionsnamn;
    std::string indentering();
    void printline(const std::string& str);
};

#endif // TRACE_H
