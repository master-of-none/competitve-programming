/* @JUDGE_ID: 1709779 12667 C++ "Last Blood"*/
//!
//! Solved By: Shrikrishna Bhat
//!

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, t, m;
    cin >> n >> t >> m;

    int firstAccepted[101][12];
    for (int i = 1; i <= t; i++)
        for (int j = 0; j < n; j++) firstAccepted[i][j] = -1;

    for (int i = 0; i < m; i++) {
        int time, team;
        char problemChar;
        string verdict;
        cin >> time >> team >> problemChar >> verdict;

        int problem = problemChar - 'A';
        if (verdict == "Yes" && firstAccepted[team][problem] == -1)
            firstAccepted[team][problem] = time;
    }

    for (int j = 0; j < n; j++) {
        int lastTime = -1, lastTeam = -1;
        for (int i = 1; i <= t; i++) {
            if (firstAccepted[i][j] != -1) {
                if (firstAccepted[i][j] > lastTime ||
                    (firstAccepted[i][j] == lastTime && i > lastTeam)) {
                    lastTime = firstAccepted[i][j];
                    lastTeam = i;
                }
            }
        }

        char problemChar = 'A' + j;
        cout << problemChar << " ";
        if (lastTime == -1)
            cout << "- -";
        else
            cout << lastTime << " " << lastTeam;
        cout << "\n";
    }

    return 0;
}