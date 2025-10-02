#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);

        if (minStack.empty()) {
            minStack.push_back(val);
        } else {
            minStack.push_back(min(minStack.back(), val));
        }
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }

private:
    vector<int> stack;
    vector<int> minStack;
};

int main() {
    MinStack stack;

    stack.push(5);
    stack.push(2);
    stack.push(3);

    cout << stack.getMin() << endl;

    return 0;
}