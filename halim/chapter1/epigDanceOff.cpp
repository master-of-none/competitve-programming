//! Kattis Problem
//! EpigDanceOff

#include <header.h>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);

    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }

    int res = 0;

    for (int col = 0; col < C; col++) {
        bool blank = true;
        for (int row = 0; row < R; row++) {
            if (grid[row][col] == '$') {
                blank = false;
                break;
            }
        }
        if (blank) res++;
    }
    cout << res + 1 << "\n";
}