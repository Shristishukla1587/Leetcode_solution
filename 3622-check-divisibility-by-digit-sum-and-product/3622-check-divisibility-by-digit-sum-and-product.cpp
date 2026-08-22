class Solution {
public:
    bool checkDivisibility(int n) {
        vector<int> v;
        int sum = 0;
        int prod = 1;
        int k = n;
        while(n > 0) {
            int digit = n % 10;
            v.push_back(digit);
            n = n / 10;
            }
            for(int i = 0; i < v.size(); i++) {
                sum += v[i];
                prod *= v[i];
                }
        if(k % (sum + prod) == 0) {
            return true;
            }
            return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna