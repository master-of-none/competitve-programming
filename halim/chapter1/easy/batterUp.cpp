#include <iostream>
using namespace std;

int main() {
  int n, sum = 0, temp;
  cin >> n;
  temp = n;

  for (int i = 0; i < n; i++) {
    int atBat;
    cin >> atBat;
    if (atBat == -1) {
      temp--;
      continue;
    }
    sum += atBat;
  }
  cout << (double)sum / temp << endl;
}