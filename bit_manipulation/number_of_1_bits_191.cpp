#include <iostream>

using namespace std;

int hammingWeight(int n) {
    int mask = 1, count = 0;

    for (int i = 0; i < 32; i++) {
        if ((mask & n) != 0) {
            count++;
        }

        mask <<= 1;
    }

    return count;
}

int main() {
    cout << hammingWeight(11) << endl;

    return 0;
}
