#include <iostream>
#include <vector>

using namespace std;

bool checkValidString(string s) {
    int open_min = 0, open_max = 0;

    for (char c : s) {
        if (c == '(') {
            open_min++;
            open_max++;
        } else if (c == ')') {
            open_min--;
            open_max--;
        } else if (c == '*') {
            open_min--;
            open_max++;
        }
        if (open_max < 0) return false;
        if (open_min < 0) open_min = 0;
    }

    return open_min == 0;
}

int main() {
    string s = "(()(**";
    cout<<checkValidString(s);

    return 0;
}