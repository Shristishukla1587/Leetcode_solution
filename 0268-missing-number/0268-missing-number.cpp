class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums[0] != 0){
            return 0;
        }
        for(int i = 0; i < n - 1; i++){
            int j = nums[i]+1;
            if(nums[i + 1] != j){
               return j;
            }
        }
        return n;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna