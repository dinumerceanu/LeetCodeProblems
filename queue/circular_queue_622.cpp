#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        arr = vector<int>(k);
        size = k;
        head = 0;
        tail = -1;
        count = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        tail = (tail + 1) % size;
        arr[tail] = value;
        count++;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        head = (head + 1) % size;
        count--;

        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return arr[head];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        
        return arr[tail];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }

private:
    vector<int> arr;
    int head, tail, count, size;
};

int main() {
    MyCircularQueue q(3);
    cout << q.enQueue(1) << endl;
    cout << q.enQueue(2) << endl;
    cout << q.enQueue(3) << endl;
    cout << q.enQueue(4) << endl;
    cout << q.Rear() << endl;
    cout << q.isFull() << endl;
    cout << q.deQueue() << endl;
    cout << q.enQueue(4) << endl;
    cout << q.Rear() << endl;

    return 0;
}
