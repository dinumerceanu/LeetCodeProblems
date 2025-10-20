#include <iostream>
#include <vector>
#include <string>

using namespace std;

int evalRPN(vector<string>& tokens) {
    vector<int> stack;

    for (string token : tokens) {
        if (token == "+") {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();

            stack.push_back(b + a);
        } else if (token == "-") {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();

            stack.push_back(b - a);
        } else if (token == "*") {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();

            stack.push_back(b * a);
        } else if (token == "/") {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();

            stack.push_back(b / a);
        } else {
            int x = stoi(token);
            stack.push_back(x);
        }
    }

    return stack.back();
}

int main() {
    vector<string> tokens = {"2","1","+","3","*"};

    cout << evalRPN(tokens) << endl;

    return 0;
}
