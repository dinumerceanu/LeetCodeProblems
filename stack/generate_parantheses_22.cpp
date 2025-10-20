#include <iostream>
#include <vector>
#include <string>

using namespace std;

void aux(int n, int& open, int& closed, vector<string>& results, string& current) {
    if (open > n || closed > n) {
        return;
    }

    if (open == n && closed == n) {
        results.push_back(current);
        return;
    }

    if (closed < open) {
        if (open < n) {
            open++;
            current.push_back('(');
            aux(n, open, closed, results, current);
            open--;
            current.pop_back();

            closed++;
            current.push_back(')');
            aux(n, open, closed, results, current);
            closed--;
            current.pop_back();
        } else {
            closed++;
            current.push_back(')');
            aux(n, open, closed, results, current);
            closed--;
            current.pop_back();
        }
    } else {
        open++;
        current.push_back('(');
        aux(n, open, closed, results, current);
        open--;
        current.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> results;
    string current;
    int open = 0, closed = 0;

    aux(n, open, closed, results, current);

    return results;
}

int main() {
    int n = 3;
    vector<string> res = generateParenthesis(n);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}
