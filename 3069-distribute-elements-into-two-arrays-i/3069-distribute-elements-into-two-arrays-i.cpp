class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2, result;
        int n = nums.size();

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2; i < n; i++) {

            if(arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }

        for(int x : arr1) {
            result.push_back(x);
        }

        for(int x : arr2) {
            result.push_back(x);
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna