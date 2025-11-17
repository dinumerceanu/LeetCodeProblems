#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    vector<string> m(numRows, "");
    int i = 0;
    int direction_y = -1;

    for (int c = 0; c < s.size(); c++) {
        m[i].push_back(s[c]);

        if (i == 0 || i == numRows - 1) {
            direction_y *= -1;
        }

        i += direction_y;
    }

    string res = "";

    for (int i = 0; i < m.size(); i++) {
        res.append(m[i]);
    }

    return res;
}

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 2;

    cout << convert(s, numRows) << endl;

    return 0;
}
