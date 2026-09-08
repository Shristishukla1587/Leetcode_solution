class Solution {
public:
    int countCommas(int n) {
        int count  = 0;
        if(n < 1000){
            return 0;
        }
        for(int k = 1000; k <= n; k++){
            count++;
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna