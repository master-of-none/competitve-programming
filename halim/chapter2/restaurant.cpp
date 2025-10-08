//! Kattis Restaurant
//!
//! Submitted by: Shrikrishna Bhat

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int pile1 = 0, pile2 = 0;

        for (int i = 0; i < n; i++) {
            string operation;
            int m;

            cin >> operation >> m;

            if (operation == "DROP") {
                cout << "DROP 2 " << m << "\n";
                pile2 += m;
            } else if (operation == "TAKE") {
                if (pile1 < m) {
                    if (pile1 > 0) {
                        cout << "TAKE 1 " << pile1 << "\n";
                        m -= pile1;
                        pile1 = 0;
                    }
                    cout << "MOVE 2->1 " << pile2 << "\n";
                    pile1 = pile2;
                    pile2 = 0;
                }
                cout << "TAKE 1 " << m << "\n";
                pile1 -= m;
            }
        }
        cout << "\n";
    }
    return 0;
}