class CustomStack {
private:
    vector<int> stack;  // Vector to store stack elements
    int maxSize;        // Maximum size of the stack
    
public:
    // Constructor to initialize the stack with maximum size
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    // Push an element onto the stack if it hasn't reached maxSize
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }
    
    // Pop and return the top element of the stack, or -1 if empty
    int pop() {
        if (stack.empty()) {
            return -1;
        }
        int top = stack.back();
        stack.pop_back();
        return top;
    }
    
    // Increment the bottom k elements of the stack by val
    void increment(int k, int val) {
        // Determine the number of elements to increment
        int n = min(k, static_cast<int>(stack.size()));
        
        // Increment the bottom n elements
        for (int i = 0; i < n; i++) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */