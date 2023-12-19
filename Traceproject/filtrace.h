#ifndef FILTRACE_H
#define FILTRACE_H

#endif // FILTRACE_H

#define USING_COUT_TRACE \
    int Trace::s_aktuelltDjup = 0; \
    Trace::Outputtype Trace::s_utskriftsMetod = Trace::output_cout;
#define USING_QDEBUG_TRACE\
    int Trace::s_aktuelltDjup = 0;\
    Trace::Outputtype Trace::s_utskriftsMetod = Trace::output_qdebug;
