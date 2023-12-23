#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <string>

using namespace std;

template <typename Containter> void skrivHorisontell(const string&message, Containter &containter){
    cout << message << ":";
    for(const auto &x: containter)
        cout <<x<<"";
    cout <<endl;
}

void provaTransorm1(){
    vector<int> vec{3,7,4,9,3,1,2,4,9,5};

    skrivHorisontell("orginalvektorn:", vec);

    auto adderaTio = [](int i) {return 10+i;};
    transform(begin(vec), end(vec), begin(vec), adderaTio);

    skrivHorisontell("efter transform:", vec);
}
void provaTransform2(){
    vector<int>vec1{3,7,4,9,3,1,2,4,9,5};
    vector<int>vec2(vec1.size());
    vector<int>vec3;

    transform(vec1.begin(), vec1.end(), vec2.begin(),[](int x) {return x*3;});

    transform(vec1.begin(), vec1.end(), back_inserter(vec3), [](int x) {return x*5;});

    skrivHorisontell("vec2", vec2);

    skrivHorisontell("vec3",vec3);
}
void provaIota(){
    vector<int> vec(10);
    skrivHorisontell("Prova iota A:", vec);
    iota(begin(vec),end(vec),42);
    skrivHorisontell("prova iota A:",vec);

    skrivHorisontell("prova iota B:", vec);
    iota(begin(vec), end(vec),0.9);
    skrivHorisontell("Prova iota B", vec);

    cout << endl;
    string str( 'z'-'a'+1, ' ' );
    iota( begin(str), end(str), 'a');
    cout << str << endl;
}
void provaGenerate_n(){
    vector<int> fibsekvens;
    auto ite = back_inserter(fibsekvens);
    auto generator = [fore=0, forefore=0]() mutable{
        int e= forefore+fore; forefore=fore; fore=e;
        cout <<e<<" ";
        return e;
    };
    generate_n(ite, 10, generator);
    cout<<endl;
    skrivHorisontell("fibsekvens:",fibsekvens);
}
void provaGenerate_n2(){
    vector<int>data;
    int antalElement = 10;
    generate_n(back_inserter(data),antalElement,[n=0] ()mutable {return n++;});
    skrivHorisontell("data:",data);
}
void provaSort(){
    string str = "Here is a pretty large number of ASCII-characters";

    sort(begin(str), end(str));
    cout << "provaSort A:" << str << endl;

    auto aForeB = [](char a, char b){return  a>b;};
    sort(begin(str), end(str), aForeB);
    cout << "ProvaSort B:"<<str<<endl;
}
struct AB{
    int m_a;
    int m_b;
};
ostream& operator <<(ostream &o, const AB &ab){
    o<< "(" << ab.m_a<<","<<ab.m_b<<")";
    return o;
}
void provaSortOchStableSort(){
    vector<AB> data;
    auto generateRandom = [](){return AB{rand()%100, rand()%2};};
    auto ite = back_inserter(data);
    generate_n(ite, 100, generateRandom);
    skrivHorisontell("fore sort",data);

    auto villkorA = [](const AB &ab1, const AB &ab2){return ab1.m_a<ab2.m_a;};
    auto villkorB = [](const AB &ab1, const AB &ab2){return ab1.m_b<ab2.m_b;};

    sort(begin(data), end(data), villkorA);
    skrivHorisontell("efter sort A:", data);

    stable_sort(begin(data), end(data), villkorB );
    skrivHorisontell("efter sort B:", data);
}
void provaRemoveIf(){
    vector<int>data(10);
    iota(begin(data), end(data), 0);
    skrivHorisontell("fore remove", data);

    auto villkor = [](int i){return  i<5;};
    auto iteFrom = remove_if(begin(data), end(data), villkor);
    skrivHorisontell("efter remove", data);
    data.erase(iteFrom,end(data));

    skrivHorisontell("efter remove pa riktigt",data);
}
void ingangTillStdAlgoritmer(){
    provaRemoveIf();
    //provaSortOchStableSort();
    //provaSort();
    //provaGenerate_n2();
    //provaGenerate_n();
    //provaIota();
    //provaTransorm1();
    //provaTransform2();
}
