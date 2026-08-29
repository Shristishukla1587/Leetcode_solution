class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        vector<pair<int, int>> sorted;

        for(int i = 0; i < nums.size(); i++){
            sorted.push_back({nums[i], i});
        }

        sort(sorted.begin(), sorted.end());

        vector<int> result(nums.size());

        int s = 0;

        for(int i = 1; i <= sorted.size(); i++){

            if(i == sorted.size() || sorted[i].first - sorted[i - 1].first > limit){

                vector<int> index;

                for(int j = s; j < i; j++){
                    index.push_back(sorted[j].second);
                }

                sort(index.begin(), index.end());

                for(int j = 0; j < index.size(); j++){
                    result[index[j]] = sorted[s + j].first;
                }

                s = i;
            }
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna