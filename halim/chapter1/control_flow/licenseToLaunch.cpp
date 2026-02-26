#include <climits>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int minVal = INT_MAX;
  int pos = 0;

  for (int i = 0; i < n; i++) {
    int junk;
    cin >> junk;
    if (junk < minVal) {
      minVal = junk;
      pos = i;
    }
  }
  cout << pos << endl;
}