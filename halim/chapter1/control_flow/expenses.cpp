#include <iostream>
using namespace std;

int main() {
  int N, res = 0;
  cin >> N;
  while (N--) {
    int val;
    cin >> val;
    if (val < 0) res += abs(val);
  }
  cout << res << endl;
}