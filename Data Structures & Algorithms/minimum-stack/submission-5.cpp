#include <climits>
class MinStack {
    int min;
    std::stack<int> stack;
    std::stack<int> minStack;
public:
    MinStack() {
        this->min = INT_MAX;
    }
    
    void push(int val) {
        stack.push(val);
        val = std::min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
            

            
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
        
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
