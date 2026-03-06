#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);

  for (size_t i = 1; i < input.length(); i++) {
    if (input[i - 1] == 's' && input[i] == 's') {
      cout << "hiss" << endl;
      return 0;
    }
  }
  cout << "no hiss" << endl;
}