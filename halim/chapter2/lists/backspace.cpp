#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    vector<char> result;

    for (char c : input) {
        if (c == '<') {
            if (!result.empty()) result.pop_back();
        } else {
            result.push_back(c);
        }
    }

    for (char c : result) cout << c;
    cout << endl;

    return 0;
}