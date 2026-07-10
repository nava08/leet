#include <stack>
#include <algorithm>

class MinStack {
private:
    // Stack stores pairs of {value, current_min}
    std::stack<std::pair<int, int>> st;

public:
    MinStack() {
        // Constructor initialization if needed
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            // The new minimum is the lesser of the current value and the previous minimum
            int current_min = std::min(val, st.top().second);
            st.push({val, current_min});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};