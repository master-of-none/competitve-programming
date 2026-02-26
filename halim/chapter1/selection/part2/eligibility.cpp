#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  cin.ignore();

  while (T--) {
    string line;
    getline(cin, line);

    stringstream ss(line);
    string word;
    vector<string> words;
    while (ss >> word) {
      words.push_back(word);
    }
    // for (auto& w : words) cout << w << "\n";
    string name = words[0];
    int pss = stoi(words[1].substr(0, 4));
    int byear = stoi(words[2].substr(0, 4));
    int courses = stoi(words[3]);

    if (pss >= 2010 || byear >= 1991) {
      cout << name << " eligible\n";
    } else if (courses >= 41) {
      cout << name << " ineligible\n";
    } else {
      cout << name << " coach petitions\n";
    }
  }
  return 0;
}