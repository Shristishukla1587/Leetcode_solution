class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> k;
        for(int i = 0 ; i < nums.size(); i++){
            int c = nums[i]*nums[i];
            k.push_back(c);
        }
        sort(k.begin(), k.end());
        return k;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna