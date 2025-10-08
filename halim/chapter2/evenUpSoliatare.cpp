#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    stack<int> s;

    for (int i = 0; i < n; i++) {
        int parity = cards[i] % 2;

        if (!s.empty() && s.top() == parity) {
            s.pop();
        } else {
            s.push(parity);
        }
    }

    cout << s.size();
}
