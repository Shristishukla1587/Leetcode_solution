class Solution {
public:
    int countDigits(int num) {
        int val = num;
        int count = 0;
        while(val != 0){
            int k = val%10;
            val = val/10;
            if( num % k == 0){
                count ++;
                }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna