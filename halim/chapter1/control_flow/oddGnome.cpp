#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> gnomes;
    while (N--) {
      int val;
      cin >> val;
      gnomes.push_back(val);
    }
    for (size_t i = 1; i < gnomes.size() - 1; i++) {
      if (gnomes[i] - gnomes[i - 1] != 1 && gnomes[i + 1] - gnomes[i] != 1) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
}