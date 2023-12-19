#include <iostream>
#include <string>
#include <optional>
#include <cstdlib>

using namespace std;

std::optional<int> intFranString(const std::string str) {
    char *endptr;
    long int result = strtol(str.c_str(), &endptr, 10);

    if (*endptr != '\0') {
        return std::nullopt;
    }
    if (result > INT_MAX || result < INT_MIN) {
        return std::nullopt;
    }
    return static_cast<int>(result);
}

void testIntFranString() {
    string input;

    while (true) {
        cout << "heltalsstrang: ";
        getline(cin, input);

        if (input == "avsluta") {
            break;
        }
        auto result = intFranString(input);

        if (result.has_value()) {
            cout << "Heltalet ar " << result.value() << endl;
        } else {
            cout << "ogiltig int" << endl;
        }
    }
}

