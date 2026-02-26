#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int val;
    cin >> val;

    if (val % 2 == 0)
      cout << val << " is even\n";
    else
      cout << val << " is odd\n";
  }
}