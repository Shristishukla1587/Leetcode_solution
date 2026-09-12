class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<vector<int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(arr.begin(), arr.end());

        // dp[i][k] = {maximum score, selected indices}
        vector<vector<pair<long long, vector<int>>>> dp(n + 1,
            vector<pair<long long, vector<int>>>(5));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Skip current interval
                auto skip = dp[i + 1][k];

                // Take current interval
                int l = i + 1;
                int r = n;

                while (l < r) {
                    int mid = l + (r - l) / 2;

                    if (arr[mid][0] > arr[i][1])
                        r = mid;
                    else
                        l = mid + 1;
                }

                auto take = dp[l][k - 1];

                take.first += arr[i][2];
                take.second.push_back(arr[i][3]);

                sort(take.second.begin(), take.second.end());

                // Choose better score
                if (take.first > skip.first) {
                    dp[i][k] = take;
                }
                else if (take.first < skip.first) {
                    dp[i][k] = skip;
                }
                else {
                    // Same score -> lexicographically smaller indices
                    if (take.second < skip.second)
                        dp[i][k] = take;
                    else
                        dp[i][k] = skip;
                }
            }
        }

        return dp[0][4].second;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna