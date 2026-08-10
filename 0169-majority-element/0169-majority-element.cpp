class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k;
        for(int i = 0 ; i < n ; i++){
            int count = 1;
            for(int j = i+1; j < n ; j++){
                if(nums[i] == nums[j]){
                    count ++;
                }
            }
            if(count > n/2){
               k = nums[i];
            }
        }
        return k;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna