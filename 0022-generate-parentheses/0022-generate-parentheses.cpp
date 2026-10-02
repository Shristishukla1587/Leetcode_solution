#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // This needs to be a separate helper function (backtrack)
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Base case: a valid combination is formed
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }

        // Add opening parenthesis if allowed
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }

        // Add closing parenthesis if it matches an open one
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

public:
    // This is the primary function LeetCode calls
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna