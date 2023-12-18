#include <iostream>
#include "trace.h"

using namespace std;
int Trace::s_aktuelltDjup = 0;
Trace::Outputtype Trace::s_utskriftsMetod = Trace::output_qdebug;

int fakultet(int n){
    tracemex(to_string(n));
    if(n <= 1){
        tracemsg("basvilkoret returnerar 1");
        return 1;
    }
    int result = n*fakultet(n-1);
    tracemsg(string("returnerar ") + to_string(result));
    return result;
}
void funcB(){
    traceme;
    tracemsg("Hello, world");
}
void funcA(){
    traceme;
    funcB();
    cout << "Fakulteten av 4 ar "<< fakultet(4)<< endl;
}


int main()
{
    cout << "Hello World!" << endl;
    traceme;
    funcA();
    return 0;
}
