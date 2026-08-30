class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();

        int front = max(minIndex, maxIndex) + 1;
        int back = n - min(minIndex, maxIndex);
        int mixed1 = (minIndex + 1) + (n - maxIndex);
        int mixed2 = (maxIndex + 1) + (n - minIndex);

        return min({front, back, mixed1, mixed2});
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna