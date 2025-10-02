#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {
        for (int i = 0; i < encoding.size(); i++) {
            if (encoding[i] == 0 && i % 2 == 0) {
                i++;
            } else {
                dq.push_back(encoding[i]);
            }
        }
    }
    
    int next(int n) {
        while (n > 0 && !dq.empty()) {
            int count = dq.front();
            dq.pop_front();
            int elem = dq.front();
            dq.pop_front();
            printf("count: %d, elem: %d, n: %d\n", count, elem, n);
            if (n > count) {
                n -= count;
            } else if (n == count) {
                return elem;
            } else {
                count -= n;
                dq.push_front(elem);
                dq.push_front(count);
                
                return elem;
            }
        }

        return -1;
    }

private:
    deque<int> dq;
};

int main() {
    vector<int> encoding = {3,8,0,9,2,5};
    RLEIterator* obj = new RLEIterator(encoding);
    cout << endl;
    
    int param_1 = obj->next(2);
    int param_2 = obj->next(1);
    int param_3 = obj->next(1);
    int param_4 = obj->next(2);

    printf("%d %d %d %d\n", param_1, param_2, param_3, param_4);

    return 0;
}
