#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string>ordlistan(){
    string path="C:/Users/filmo/Desktop/Desktop/1st year/OOP/OOP Labbar/ordlista.txt";
    vector<string>ordvektor;
    ifstream filen(path);
    string ord;
    while(filen>>ord){
        ordvektor.push_back(ord);
    }
    return ordvektor;
}
string sorteraStrang(const string& str){
    string sorteradStr = str;
    sort(sorteradStr.begin(), sorteradStr.end());
    return sorteradStr;
}
void skrivUtAnagram(vector<string>&ordlista){
    map<string, set<string>> anagramMap;

    for(const string& ord: ordlista){
        string sorteradOrd = sorteraStrang(ord);
        anagramMap[sorteradOrd].insert(ord);
    }
    for(const auto& par: anagramMap){
        if(par.second.size()>1){
            cout << "Anagram: ";
            for(const string&ord: par.second){
                cout << ord <<"";
            }
            cout << endl;
        }
    }
}

void provaAnagram(){
    auto ordlista = ordlistan();
    skrivUtAnagram(ordlista);
}
