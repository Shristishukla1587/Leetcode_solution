class Solution {
public:
    int dp[101][101];
    vector<int> suffix;
    int n;

    int solve(int i, int M, vector<int>& piles) {
        if (i >= n) return 0;

        // agar saare remaining piles le sakte hain
        if (i + 2 * M >= n)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M; X++) {
            ans = max(ans,
                      suffix[i] - solve(i + X, max(M, X), piles));
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.resize(n + 1, 0);

        // suffix sum
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 1, piles);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna