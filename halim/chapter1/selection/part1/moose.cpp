#include <algorithm>
#include <ios>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int left, right;
  cin >> left >> right;

  if (left == 0 && right == 0) {
    cout << "Not a moose\n";
    return 0;
  }

  if (left == right)
    cout << "Even " << left + right << "\n";
  else if (left != right)
    cout << "Odd " << 2 * max(left, right) << "\n";
}