#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  cin.ignore();
  while (T--) {
    string line;
    getline(cin, line);

    stringstream ss(line);

    int a, b;
    char op;

    if (ss >> a >> op >> b && op == '+') {
      cout << a + b << endl;
    } else {
      cout << "skipped\n";
    }
  }
}