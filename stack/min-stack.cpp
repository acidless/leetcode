// Problem: Min Stack
// Link: https://leetcode.com/problems/min-stack/
// Approach: Custom stack implementation


class MinStack {
public:
    void push(int val) {
        auto min = val;
        if(data.size()) {
            min = std::min(min, data.top().second);
        }

        data.push(std::make_pair(val, min));
    }
    
    void pop() {
        data.pop();
    }
    
    int top() {
        return data.top().first;
    }
    
    int getMin() {
        return data.top().second;
    }
private:
    std::stack<std::pair<int, int>> data;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
