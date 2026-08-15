class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        vector<int> zeros(n, 0);

        if (nums == zeros) {
            return 0;
        }

        int x = 0;

        for (int num : nums) {
            x ^= num;
        }

        return x ? n : n - 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna