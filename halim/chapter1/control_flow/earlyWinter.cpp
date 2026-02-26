#include <iostream>
using namespace std;

int main() {
  int n, dm;
  cin >> n >> dm;

  int count = 0;
  bool counting = true;

  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    if (counting && d > dm)
      count++;
    else
      counting = false;
  }

  if (count == n)
    cout << "It had never snowed this early!\n";
  else
    cout << "It hadn't snowed this early in " << count << " years!\n";
}