#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  string s;
  unordered_map<char, int> map = {
      {'B', 1}, {'F', 1}, {'P', 1}, {'V', 1}, {'C', 2}, {'G', 2},
      {'J', 2}, {'K', 2}, {'Q', 2}, {'S', 2}, {'X', 2}, {'Z', 2},
      {'D', 3}, {'T', 3}, {'L', 4}, {'M', 5}, {'N', 5}, {'R', 6}};

  while (getline(cin, s)) {
    for (size_t i = 0; i < s.size(); i++) {
      if (map[s[i]] == 0) continue;
      if (i >= 1 && map[s[i - 1]] == map[s[i]]) continue;
      cout << map[s[i]];
    }
    cout << "\n";
  }
}