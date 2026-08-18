class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;

        for (int x = 0; x <= 50; x++) {
            int count = 0;

            for (int i = 0; i <= n - k; i++) {
                bool found = false;

                for (int j = i; j < i + k; j++) {
                    if (nums[j] == x) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    count++;
                }
            }

            if (count == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna