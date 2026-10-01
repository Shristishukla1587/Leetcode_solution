class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // If it is an opening bracket, push the expected closing bracket
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } 
            // If it is a closing bracket, check if stack is empty or top doesn't match
            else {
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }
        
        // If stack is empty, all opening brackets were matched
        return st.empty();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna