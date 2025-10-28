#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

string telegraph_style(const string& input) {
    std::string result = input;

    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::toupper(c); });

    bool lastWasSpace = false;
    for(char c : result) {
        if(!std::isalpha(c) && !std::isdigit(c) && !std::isspace(c) && c != '.') {
            result.erase(std::remove(result.begin(), result.end(), c), result.end());
        }
        if(c == ' ') {
            if(!lastWasSpace) {
                result += c;
                lastWasSpace = true;
            }
            else {
                result += c;
                lastWasSpace = false;
            }
        }
    }

    return result + "STOP";
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string result = telegraph_style(input);
    cout << "Telegraph Style: " << result << endl;

    return 0;
}