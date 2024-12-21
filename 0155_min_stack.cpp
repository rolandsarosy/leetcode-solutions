// https://leetcode.com/problems/min-stack/description/

// O(1) solution using 2 stacks where one is the counter, and the other holds the found minimum elements and their frequencies
class MinStack {
    public:
        MinStack() {
        
        }
        
        // push to the back of the stack
        // if the value is smaller than the current top (pair.first), add it to the currentMinFrequency stack with a frequency of one
        // if the value is the same, just increase the frequency
        void push(int val) {
            counterStack.push_back(val);

            if (currentMinFrequency.size() == 0) {
                currentMinFrequency.push_back({val, 1});
                return;
            }

            if (val < currentMinFrequency.back().first) {
                currentMinFrequency.push_back({val,1});
            } else if (val == currentMinFrequency.back().first) {
                int currentFrequency = currentMinFrequency.back().second;
                currentMinFrequency.pop_back();
                currentMinFrequency.push_back({val, ++currentFrequency});
            }
        }
        
        // pop the back
        // check if the popped element is on the top of the currentMinFrequency stack
        // if not, proceed
        // if so, change the count of the top of the stack by one, if it reaches zero, just pop it
        void pop() {
            int toPop = counterStack.back();
            counterStack.pop_back();

            if (toPop == currentMinFrequency.back().first) {
                if (currentMinFrequency.back().second == 1) {
                    currentMinFrequency.pop_back();
                } else {
                    int currentFrequency = currentMinFrequency.back().second;
                    currentMinFrequency.pop_back();
                    currentMinFrequency.push_back({toPop, --currentFrequency});
                }
            }
        }
        
        int top() {
            return counterStack.back();
        }
        
        int getMin() {
            return currentMinFrequency.back().first;
        }

    private:
        deque<int> counterStack;
        deque<pair<int, int>> currentMinFrequency; // <currentMin, frequency>

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
