#include <iostream>
using namespace std;

int main() {
  int n, res = 0;
  cin >> n;
  while (n--) {
    int temp;
    cin >> temp;

    if (temp < 0) res++;
  }
  cout << res << endl;
}