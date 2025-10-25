#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool checkValidString(string s) {
    int openMin = 0, openMax = 0;

    for (char c : s) {
        if (c == '(') {
            openMin++;
            openMax++;
        } else if (c == ')') {
            openMin--;
            openMax--;
        } else {
            openMin--;
            openMax++;
        }

        if (openMin < 0) {
            openMin = 0;
        }

        if (openMax < 0) {
            return false;
        }
    }

    return openMin == 0;
}

int main() {
    string s = "()";

    if (checkValidString(s)) {
        cout << "TRUE\n";
    } else {
        cout << "FALSE\n";
    }

    return 0;
}
