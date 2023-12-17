#ifndef TRACE_H
#define TRACE_H
#include <string>

class Trace
{
public:
    enum Outputtype{output_cout, output_qdebug};
    Trace(const std::string& funktionsnamn);
    Trace(const std::string& funktionsnamn, const std::string& extra);
    ~Trace();

    void message(const std::string& str);

private:
    std::string m_funktionsnamn;
    std::string indentering();
    void printline(const std::string& str);
};

#endif // TRACE_H
