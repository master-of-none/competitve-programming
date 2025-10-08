#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    stack<int> stack;
    stack.push(0);

    for (int i = 0; i < K; i++) {
        string command;
        cin >> command;

        if (command == "undo") {
            int x;
            cin >> x;
            while (x-- && !stack.empty()) stack.pop();
            if (stack.empty()) stack.push(0);
        } else {
            int move = stoi(command);
            int newPos = (stack.top() + move) % N;
            if (newPos < 0) newPos += N;
            stack.push(newPos);
        }
    }

    cout << stack.top() << "\n";
    return 0;
}