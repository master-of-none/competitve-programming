#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main() {
  int integer;
  int cases = 1;
  while (cin >> integer) {
    int maxVal = INT_MIN, minVal = INT_MAX;
    while (integer--) {
      int temp;
      cin >> temp;
      maxVal = max(maxVal, temp);
      minVal = min(minVal, temp);
    }
    cout << "Case " << cases++ << ": " << minVal << " " << maxVal << " "
         << maxVal - minVal << endl;
  }
}