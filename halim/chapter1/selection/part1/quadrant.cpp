#include <ios>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x;
  int y;

  cin >> x;
  cin >> y;

  if (x > 0 && y > 0)
    cout << 1 << endl;
  else if (x < 0 && y > 0)
    cout << 2 << endl;
  else if (x < 0 && y < 0)
    cout << 3 << endl;
  else if (x > 0 && y < 0)
    cout << 4 << endl;

  return 0;
}