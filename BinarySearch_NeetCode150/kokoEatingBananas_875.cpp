#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int max = 0, left, right, m;
    long long hours;

    for (int i = 0; i < piles.size(); i++) {
        if (piles[i] > max) max = piles[i];
    }

    left = 1, right = max;
    while (left <= right) {
        m = (left + right) / 2;
        hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + m - 1) / m;
        }
        if (hours > h) left = m + 1;
        else right = m - 1;
    }
    return left;
}

int main() {
    vector<int> piles = {30,11,23,4,20};
    int h = 5;
    cout<<minEatingSpeed(piles, h)<<endl;

    return 0;
}