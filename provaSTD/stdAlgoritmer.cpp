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

void ingangTillStdAlgoritmer(){
    //provaTransorm1();
    provaTransform2();
}
