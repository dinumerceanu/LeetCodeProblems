#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> partitionLabels(string s) {
    unordered_map<char, pair<int, int>> map;
    vector<pair<int, int>> merged_intervals;
    vector<int> res;

    for (int i = 0; i < s.size(); i++) {
        if (map.find(s[i]) == map.end()) {
            map[s[i]] = {i, i};
        } else {
            map[s[i]] = {map[s[i]].first, i};
        }
    }

    vector<pair<int, int>> aux;

    for (const auto& map_entry : map) {
        aux.push_back(map_entry.second);
    }

    sort(aux.begin(), aux.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.first < b.first;});

    pair<int, int> current_interval = aux[0];

    for (int i = 1; i < aux.size(); i++) {
        if (aux[i].first > current_interval.second) {
            merged_intervals.push_back(current_interval);
            current_interval = aux[i];
        } else {
            current_interval = {current_interval.first, max(current_interval.second, aux[i].second)};
        }
    }

    if (merged_intervals.empty() || merged_intervals[merged_intervals.size() - 1] != current_interval) {
        merged_intervals.push_back(current_interval);
    }

    for (const auto& elem : merged_intervals) {
        res.push_back(elem.second - elem.first + 1);
    }

    return res;
}

int main() {
    string s = "eccbbbbdec";

    vector<int> res = partitionLabels(s);

    for (const auto& elem : res) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
