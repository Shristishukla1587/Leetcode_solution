class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; i += 2) {
            if(nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }

        return nums[nums.size() - 1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna