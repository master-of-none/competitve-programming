#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool compare(const string& a, const string& b) {
    string la = a, lb = b;
    transform(la.begin(), la.end(), la.begin(), ::tolower);
    transform(lb.begin(), lb.end(), lb.begin(), ::tolower);
    return la < lb;
}
int main() {
    while (1) {
        int r, c;
        cin >> r >> c;
        if (r == 0 && c == 0) {
            break;
        }
        vector<vector<char>> nums(r, vector<char>(c));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> nums[i][j];
            }
        }
        vector<string> words;
        for (int j = 0; j < c; j++) {
            string word;
            for (int i = 0; i < r; i++) {
                word += nums[i][j];
            }
            words.push_back(word);
        }

        sort(words.begin(), words.end(), compare);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << words[j][i];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}