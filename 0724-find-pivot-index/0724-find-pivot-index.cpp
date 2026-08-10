class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int sum1 = 0;
            int sum2 = 0;

            // left sum
            for (int j = 0; j < i; j++) {
                sum1 += nums[j];
            }

            // right sum
            for (int j = i + 1; j < n; j++) {
                sum2 += nums[j];
            }

            if (sum1 == sum2) {
                return i;
            }
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna