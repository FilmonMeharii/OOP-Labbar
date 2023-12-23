#include <iostream>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

void provaVector(){
    vector<int>behallare{3,3,3,2,2,1,4,4,4,4};
    cout <<"Behallare.size() = " << behallare.size() <<endl;

    for(auto tal: behallare)
        cout <<tal<<" ";
    cout << endl;
}
void provaSet(){
    set<int>behallare{3,3,3,2,2,1,4,4,4,4};
    cout <<"Behallare.size() = " << behallare.size() <<endl;

    for(auto tal: behallare)
        cout <<tal<<" ";
    cout << endl;
}

struct Person{
    string m_fornamn;
    string m_efternamn;

    bool operator<(const Person& annan) const{
        if(m_fornamn != annan.m_fornamn)
            return m_fornamn < annan.m_fornamn;
        return m_efternamn < annan.m_efternamn;
    }
};
void provaPersonset(){
    set<Person>personSet;

    personSet.insert({"Alice", "Andersson"});
    personSet.insert({"Bob", "Bengt"});
    personSet.insert({"Charlie", "Carlsson"});

    for(const auto& person: personSet){
        cout << "Fornman: "<<person.m_fornamn<<endl << "Efternman: "<<person.m_efternamn<<endl<<endl;
    }
}
vector<vector<double>>matris(int antalRader, int antalkolumner){
    vector<vector<double>>resultat(antalRader , vector<double>(antalkolumner, 0.0));
    return resultat;
}
void testaMatris(){
    const int antalR=20;
    const int antalK =10;
    auto m = matris(antalR, antalK);
    assert(m.size()== antalR);
    for(int r=0; r<antalR; ++r)
        assert(m[r].size()==antalK);
    assert(m[antalR-1][antalK-1]==0);
    cout << "testaMatris lyckades"<< endl;
}
template <typename T>
vector<vector<T>>matris(int antalRader, int antalkolumner, const T& initVarde=T()){
    return vector<vector<T>>(antalRader , vector<T>(antalkolumner, initVarde));
}
void testaTemplateMatris(){
    const int antalR=20;
    const int antalK =10;
    auto m = matris(antalR, antalK);
    auto mD = matris<double>(antalR, antalK);

    assert(m== mD);
    auto mC = matris<char>(antalR, antalK);
    assert(sizeof (mC[0][0])==1);
    assert(m[antalR-1][antalK-1]==0);
    cout << "testaTemplateMatris lyckades"<< endl;
}

void provaContainrar(){
    testaTemplateMatris();
    //testaMatris();
    //provaPersonset();
    //provaSet();
    //provaVector();
}
