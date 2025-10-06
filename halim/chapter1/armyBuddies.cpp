/* @JUDGE_ID: 1709779 12356 C++ "Army Buddies"*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int S, B;

    while (cin >> S >> B && (S || B)) {
        vector<int> left(S + 2), right(S + 2);

        for (int i = 1; i <= S; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
        }

        while (B--) {
            int L, R;
            cin >> L >> R;

            int leftBuddy = left[L];
            int righBuddy = right[R];

            if (leftBuddy < 1)
                cout << "*";
            else
                cout << leftBuddy;

            cout << " ";

            if (righBuddy > S)
                cout << "*";
            else
                cout << righBuddy;

            cout << "\n";

            if (leftBuddy >= 1) right[leftBuddy] = righBuddy;
            if (righBuddy <= S) left[righBuddy] = leftBuddy;
        }
        cout << "-\n";
    }
    return 0;
}