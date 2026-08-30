class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int count = 0;
        vector<int> k;
        int n = nums.size();
        auto minit = min_element(nums.begin(),nums.end()) - nums.begin();
        auto maxit = max_element(nums.begin(),nums.end()) - nums.begin();
        int t = max(minit, maxit) + 1; //Remove index from front
        k.push_back(t);
        int l = n - min(minit, maxit); // remove index from back
        k.push_back(l);
        int c = (minit + 1) + (n - maxit); // onr from front and one from back
         k.push_back(c);
        int j = (maxit + 1) + (n - minit); // max from ront and min from back
         k.push_back(j);
         return *min_element(k.begin(),k.end());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna