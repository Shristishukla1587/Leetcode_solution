class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int mini = *min_element(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            sum += nums[i] - mini;
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna