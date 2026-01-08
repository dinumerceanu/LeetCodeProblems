#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> map;
    priority_queue<pair<int, char>> q;
    
    for (int i = 0; i < s.size(); i++) {
        map[s[i]]++;
    }

    for (const auto& map_entry : map) {
        q.push({map_entry.second, map_entry.first});
    }

    string res = "";
    while (!q.empty()) {
        int count = q.top().first;
        char c = q.top().second;
        q.pop();

        for (int i = 0; i < count; i++) {
            res.push_back(c);
        }
    }

    return res;
}

int main() {
    string s = "tree";

    cout << frequencySort(s) << endl;

    return 0;
}