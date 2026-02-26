#include <ios>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c, n;
  cin >> a >> b >> c >> n;

  if (n < 3) {
    cout << "NO\n";
    return 0;
  };
  if (a >= 1 && b >= 1 && c >= 1 && a + b + c >= n)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}