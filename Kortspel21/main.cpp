#include <iostream>
#include "korthand.h"
#include "bankir.h"
#include "kort.h"
#include "spelare.h"

using namespace std;

int main()
{
    cout << "Kortspelet 21" << endl;

    Bankir bank;
    Spelare spelare;
    bank.registreraSpelare(&spelare);

    while(bank.harRegistreradeSpelare())
        bank.spelaEnOmgang();
    return 0;
}
