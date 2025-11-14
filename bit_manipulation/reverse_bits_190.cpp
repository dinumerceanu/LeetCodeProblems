#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int reverseBits(int n) {
    int rev = 0;

    for (int i = 0; i < 32; i++) {
        rev = (rev << 1) | (n & 1);
        n >>= 1;
    }

    return rev;
}

int main() {
    cout << reverseBits(25) << endl;

    return 0;
}
