class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Find all palindromes
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i + 1 <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        // dp2[i] = maximum palindromes we can take
        // from substring s[0...i-1]
        vector<int> dp2(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // Don't take a palindrome ending at i-1
            dp2[i] = dp2[i - 1];

            // Try every starting point
            for (int j = 0; j < i; j++) {
                if (i - j >= k && dp[j][i - 1]) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }

        return dp2[n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna