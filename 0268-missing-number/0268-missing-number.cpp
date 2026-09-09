class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalsum = n * (n + 1)/2;
        int arraysum = 0;
        for(int j: nums){
            arraysum += j;
        }
        return totalsum - arraysum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna