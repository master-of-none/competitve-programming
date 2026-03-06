#include <cctype>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    unordered_map<char, int> map;

    for (char c : s) {
      if (isalpha(c)) map[c]++;
    }

    int max = INT_MIN;
    for (auto pair : map) {
      if (pair.second > max) max = pair.second;
    }
    for (char c = 'A'; c <= 'Z'; c++) {
      if (map[c] == max) cout << c;
    }
    for (char c = 'a'; c <= 'z'; c++) {
      if (map[c] == max) cout << c;
    }
    cout << " " << max << endl;
  }
}