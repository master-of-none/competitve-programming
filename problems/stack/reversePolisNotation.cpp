#include "header.h"
using namespace std;

int evalRPN(vector<string> &tokens) {
    std::stack<int> stack;

    for (string &c : tokens) {
        if (c == "+") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a + b);
        } else if (c == "*") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a * b);
        } else if (c == "-") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(b - a);
        } else if (c == "/") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(b / a);
        } else {
            stack.push(stoi(c));
        }
    }
    return stack.top();
}