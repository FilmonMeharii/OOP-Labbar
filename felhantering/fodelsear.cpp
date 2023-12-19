#include <iostream>
#include <string>
#include <optional>

using namespace std;


bool hittadeFodelsearFranNamn(const std::string namn, int *pFodelsear){
    if(namn == "Newton"){
        *pFodelsear =1642;
        return true;
    }else if(namn == "Euklides"){
        *pFodelsear = -325;
        return true;
    }else{
        return false;
    }
}
void provaHittadeFodelsear(){
    string namn;
    cout << "namn: ";
    cin >> namn;
    int fodelsear;
    if(hittadeFodelsearFranNamn(namn, &fodelsear)){
        cout << namn << " foddes " << fodelsear << "."<< endl;
    }else{
        cout << namn << " ar en okand person."<<endl;
    }
}
std::optional<int> fodelsearFranNamn(const std::string namn){
    if(namn=="Newton"){
        return 1642;
    }else if(namn=="Euklides"){
        return -325;
    }else{
        return nullopt;
    }
}
void provaFodelsear(){
    string namn;
    cout << "namn: ";
    cin >> namn;
    auto fodelsear = fodelsearFranNamn(namn);
    if(fodelsear.has_value()){
        cout << namn << " foddes " << fodelsear.value() << "."<< endl;
    }else{
        cout << namn << " ar en okand person."<<endl;
    }
}
void ingangTillFodelsear(){
    provaHittadeFodelsear();
    provaFodelsear();
}
