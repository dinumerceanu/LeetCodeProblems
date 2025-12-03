#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        myRects = rects;
        int total = 0;
        
        for (int i = 0; i < rects.size(); i++) {
            total += (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            prefix.push_back(total);
        }
    }

    vector<int> pick() {
        vector<int> point;
        int totalPoints = prefix.back();
        int target = random_between(1, totalPoints);
        int rect = lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();

        point.push_back(random_between(myRects[rect][0], myRects[rect][2]));
        point.push_back(random_between(myRects[rect][1], myRects[rect][3]));

        return point;
    }

private:
    vector<vector<int>> myRects;
    vector<int> prefix;

    int random_between(int start, int end) {
        static random_device rd;  
        static mt19937 gen(rd()); 
        uniform_int_distribution<> dist(start, end);

        return dist(gen);
    }
};

int main() {
    vector<vector<int>> rects = {{-2, -2, 1, 1}, {2, 2, 4, 6}};

    Solution* obj = new Solution(rects);
    vector<int> res = obj->pick();
    res = obj->pick();
    res = obj->pick();
    res = obj->pick();
    res = obj->pick();

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
