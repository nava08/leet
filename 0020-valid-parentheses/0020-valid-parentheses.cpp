#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // If it's an opening bracket, push to stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If it's a closing bracket
            else {
                // If stack is empty, there's no matching opening bracket
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                st.pop();
                
                // Check if the popped bracket matches the current closing bracket
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }
        
        // If stack is empty, all brackets were matched correctly
        return st.empty();
    }
};