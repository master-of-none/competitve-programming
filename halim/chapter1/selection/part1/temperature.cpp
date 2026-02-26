#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  double x, y;
  cin >> x >> y;

  if (y == 1) {
    if (x == 0)
      cout << "ALL GOOD" << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  } else {
    double ans = -x / (y - 1);
    cout << fixed << setprecision(9) << ans << endl;
  }
  return 0;
}