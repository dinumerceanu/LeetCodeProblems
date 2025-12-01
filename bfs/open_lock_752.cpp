#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int openLock(vector<string>& deadends, string target) {
    queue<string> q;
    q.push("0000");
    unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
    unordered_set<string> visited;
    visited.insert("0000");

    if (deadendsSet.count("0000")) {
        return -1;
    }

    int level = 0, onLevel = 1, onNextLevel = 0;

    while (!q.empty()) {
        string curr = q.front();
        q.pop();
        onLevel--;

        if (curr == target) {
            return level;
        }

        for (int i = 0; i < 4; i++) {
            char c = curr[i];
            char up = (c == '9' ? '0' : c + 1);
            char down = (c == '0' ? '9' : c - 1);

            string greater = curr;
            greater[i] = up;

            if (!visited.count(greater) && !deadendsSet.count(greater)) {
                q.push(greater);
                onNextLevel++;
                visited.insert(greater);
            }

            string smaller = curr;
            smaller[i] = down;

            if (!visited.count(smaller) && !deadendsSet.count(smaller)) {
                q.push(smaller);
                onNextLevel++;
                visited.insert(smaller);
            }
        }

        if (onLevel == 0) {
            onLevel = onNextLevel;
            onNextLevel = 0;
            level++;
        }
    }

    return -1;
}

int main() {
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";

    cout << openLock(deadends, target) << endl;
    
    return 0;
}
