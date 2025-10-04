#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> word_fq;
    priority_queue<pair<int, string>> heap;
    vector<pair<string, int>> res;
    vector<string> final;

    for (int i = 0; i < words.size(); i++) {
        if (word_fq.find(words[i]) == word_fq.end()) {
            word_fq[words[i]] = 1;
        } else {
            word_fq[words[i]]++;
        }
    }

    for (auto& p : word_fq) {
        heap.push({p.second, p.first});
    }

    for (int i = 0; i < word_fq.size(); i++) {
        res.push_back({heap.top().second, heap.top().first});
        heap.pop();
    }

    sort(res.begin(), res.end(),
        [] (const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
    
    for (int i = 0; i < k; i++) {
        // cout << res[i].first << " " << res[i].second << endl;
        final.push_back(res[i].first);
    }

    return final;
}

int main() {
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 1;

    vector<string> res = topKFrequent(words, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}
