#include <iostream>
#include "trace.h"

using namespace std;

int fakultet(int n){
    Trace traceobject("fakultet", to_string(n));
    if(n <= 1){
        traceobject.message("basvilkoret returnerar 1");
        return 1;
    }
    int result = n*fakultet(n-1);
    traceobject.message(string("returnerar ") + to_string(result));
    return result;
}
void funcB(){
    Trace traceObject("funkB");
    traceObject.message("Hello, world");
}
void funcA(){
    Trace traceObject("funkA");
    funcB();
    cout << "Fakulteten av 4 ar "<< fakultet(4)<< endl;
}


int main()
{
    cout << "Hello World!" << endl;
    Trace traceObject("main");
    funcA();
    return 0;
}
