class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int maxit = nums[0], l;
            int minit = nums[i];
            for(int j = 0; j <= i; j++){
                maxit = max(maxit , nums[j]);

            }
            for(int j = i; j < n; j++){
                minit = min(minit, nums[j]);
            }
            if(maxit - minit <= k){
                return i;
            }
        }
            return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna