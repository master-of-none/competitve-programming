#include <iostream>
using namespace std;

int main() {
  int dataSet;
  while (cin >> dataSet) {
    if (dataSet == -1) break;
    int s, oldT = 0, t, res = 0;
    while (dataSet--) {
      cin >> s;
      cin >> t;
      res += (s * (t - oldT));
      oldT = t;
    }
    cout << res << " miles\n";
  }
}