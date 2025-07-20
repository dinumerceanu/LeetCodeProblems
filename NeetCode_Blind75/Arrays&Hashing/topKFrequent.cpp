#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    map<int, int> freqs; 
    for (int i = 0; i < nums.size(); i++) {
        freqs[nums[i]]++;
    }

    vector<pair<int, int>> pairs(freqs.begin(), freqs.end());
    sort(pairs.begin(), pairs.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    });

    for (int i = 0; i < k; i++) {
        res.push_back(pairs[i].first);
    }

    return res;
}

int main() {
    ifstream fin("file.in");
    
    vector<int> nums;
    int n, x, k;

    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> x;
        nums.push_back(x);
    }
    fin >> k;
    
    vector<int> res = topKFrequent(nums, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
