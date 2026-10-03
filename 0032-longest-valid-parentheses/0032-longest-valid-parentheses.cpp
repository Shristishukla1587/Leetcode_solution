class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        stack<int> st;
        
        // Push -1 as a base sentinel boundary for valid substrings
        st.push(-1);
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                // Store the index of the opening bracket
                st.push(i);
            } else {
                // Pop the last unmatched opening bracket index (or sentinel)
                st.pop();
                
                if (st.empty()) {
                    // If stack is empty, this ')' is unmatched. 
                    // Update the sentinel base to the current index.
                    st.push(i);
                } else {
                    // Valid substring found: compute distance from the last unmatched index
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        
        return max_len;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna