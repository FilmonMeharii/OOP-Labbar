#ifndef INTERVALL_H
#define INTERVALL_H


class Intervall
{
public:
    struct iterator{
        iterator(int tal): m_tal(tal){}
        int& operator*() {return m_tal;}
        iterator operator++(){ m_tal+=1; return *this;}
        bool operator!=(iterator rhs) { return m_tal != rhs.m_tal;}

        int m_tal;
    };

    Intervall(int b, int e) : m_begin(b), m_end(e){}
    Intervall(int e) : m_begin(0), m_end(e){}

    iterator begin() {return m_begin;}
    iterator end() {return m_end;}
private:
    iterator m_begin;
    iterator m_end;
};
#endif // INTERVALL_H
