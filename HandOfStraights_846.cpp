#include <iostream>
#include <vector>

using namespace std;

vector<int> slice(vector<int>& v, int start, int end) {
    if (start < 0) start = 0;
    if (end > v.size()) end = v.size();
    if (start > end) return {};

    return vector<int>(v.begin() + start, v.begin() + end);
}

vector<int> merge(vector<int> a, vector<int> b) {
    int i = 0, j = 0;
    vector<int> aux;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            aux.push_back(a[i]);
            i++;
        } else if (a[i] > b[j]) {
            aux.push_back(b[j]);
            j++;
        } else {
            aux.push_back(a[i]);
            aux.push_back(b[j]);
            i++;
            j++;
        }
    }
    while (i < a.size()) {
        aux.push_back(a[i++]);
    }
    while (j < b.size()) {
        aux.push_back(b[j++]);
    }

    return aux;
}

vector<int> mergesort(vector<int> array) {
    if (array.size() <= 1) return array;

    int m = array.size() / 2;
    vector<int> left = mergesort(slice(array, 0, m));
    vector<int> right = mergesort(slice(array, m, array.size()));

    return merge(left, right);
}

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) {
        return false;
    }
    vector<int> sorted_hand = mergesort(hand);
    int taken = 0;
    for(int i = 0; i < hand.size() / groupSize; i++) {
        int j = 0, previous = -2, groupSize_copy = groupSize;
        while (j < hand.size() && groupSize_copy > 0) {
            if (sorted_hand[j] != -1) {
                if (previous == -2 || sorted_hand[j] == previous + 1) {
                    previous = sorted_hand[j];
                    sorted_hand[j] = -1;
                    taken++;
                    groupSize_copy--;
                }
            }
            j++;
        }
    }
    if (taken == hand.size()) {
        return true;
    }
    return false;
}

int main() {
    int groupSize = 3;
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    cout<<isNStraightHand(hand, groupSize);

    return 0;
}