class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        int l =0;
        int r=n-1;
        int id = n-1;
        while(l<=r){
            int ls = nums[l]*nums[l];
            int rs= nums[r]*nums[r];

            if(ls>rs){
                res[id]=ls;
                l++;
            }
            else{
                res[id]= rs;
                r--;
            }
            id--;
        }
      
        return res;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna