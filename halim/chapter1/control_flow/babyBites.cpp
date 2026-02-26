#include <iostream>
#include <stack>
using namespace std;

int main() {
  int val;
  cin >> val;
  stack<int> s;

  for (int i = val; i >= 1; i--) {
    s.push(i);
  }

  while (val--) {
    string word;
    cin >> word;
    if (word == "mumble") {
      s.pop();
      continue;
    }
    if (stoi(word) == s.top()) {
      s.pop();
    }
  }
  if (!s.empty())
    cout << "something is fishy\n";
  else
    cout << "makes sense\n";
  return 0;
}