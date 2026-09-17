#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore();

  while (N--) {
    int K;
    cin >> K;
    cin.ignore();

    unordered_map<char, int> price;

    for (int i = 0; i < K; i++) {
      string line;
      getline(cin, line);

      char c = line[0];
      int value = stoi(line.substr(2));

      price[c] = value;
    }

    int M;
    cin >> M;
    cin.ignore();

    long long total = 0;

    for (auto l = 0; l < M; l++) {
      string line;
      getline(cin, line);

      for (char c : line) {
        if (price.count(c)) {
          total += price[c];
        }
      }
    }
    cout << total / 100 << ".";
    cout << (total % 100 < 10 ? "0" : "");
    cout << total % 100 << "$\n";
  }
  return 0;
}
