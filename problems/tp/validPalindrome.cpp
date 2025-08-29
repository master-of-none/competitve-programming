#include <cctype>
#include <iostream>
using namespace std;

bool isPalindrome(string s) {
    int l = 0;
    int r = s.size() - 1;

    while (l < r) {
        while (l < r and !isAlphaNum(s[l])) {
            l += 1;
        }
        while (l < r and !isAlphaNum(s[r])) {
            r -= 1;
        }

        if (tolower(s[l]) != tolower(s[r])) {
            return false;
        }
        l += 1;
        r -= 1;
    }
    return true;
}

bool isAlphaNum(char c) {
    return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' ||
            c >= '0' && c <= '9');
}