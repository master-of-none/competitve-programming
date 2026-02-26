#include <iostream>
using namespace std;

int main() {
  int x, y;

  while (cin >> x >> y) {
    if (x == 0 && y == 0) break;
    if (x + y == 13) {
      cout << "Never speak again.\n";
      continue;
    } else if (x == y)
      cout << "Undecided.\n";
    else if (x > y)
      cout << "To the convention.\n";
    else
      cout << "Left beehind.\n";
  }
  return 0;
}