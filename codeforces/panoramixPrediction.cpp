#include <iostream>

using namespace std;

bool isPrime(int num) {
  if (num < 2)
    return false;

  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int main() {
  int n;
  int m;

  cin >> n >> m;
  int next = n + 1;

  while (!isPrime(next)) {
    next++;
  }

  if (next == m)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
