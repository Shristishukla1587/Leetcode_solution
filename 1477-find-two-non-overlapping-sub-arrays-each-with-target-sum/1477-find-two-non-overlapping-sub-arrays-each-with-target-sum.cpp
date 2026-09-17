class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;
        int len = INT_MAX;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int currLen = right - left + 1;

                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, currLen + best[left - 1]);
                }

                len = min(len, currLen);
            }

            best[right] = len;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna