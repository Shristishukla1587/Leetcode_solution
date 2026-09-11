class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int p = 1;
        while(n>0){
            int c= n%10;
            p *= c;
            sum += c;
            n = n/10;
        }
        int k = p - sum;
        return k;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna