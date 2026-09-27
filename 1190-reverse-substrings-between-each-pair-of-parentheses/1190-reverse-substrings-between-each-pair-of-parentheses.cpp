class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> openIdxs;
        
        // Step 1: Pre-calculate matching parentheses pairs like teleporters
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                openIdxs.push(i);
            } else if (s[i] == ')') {
                int j = openIdxs.top();
                openIdxs.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        
        // Step 2: Traverse and build the result string
        string ans = "";
        int direction = 1; // 1 means moving right, -1 means moving left
        
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];        // Teleport to the matching parenthesis
                direction = -direction; // Reverse the walking direction
            } else {
                ans += s[i];        // Add regular characters to the result
            }
        }
        
        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna