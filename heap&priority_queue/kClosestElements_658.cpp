#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int, int>> q;
    vector<int> res;

    for (int i = 0; i < arr.size(); i++) {
        q.push({abs(arr[i] - x), arr[i]});

        if (q.size() > k) {
            q.pop();
        }
    }

    for (int i = 0; i < k; i++) {
        res.push_back(q.top().second);
        q.pop();
    }
    sort(res.begin(), res.end());

    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4, x = 3;

    vector<int> res = findClosestElements(arr, k, x);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
