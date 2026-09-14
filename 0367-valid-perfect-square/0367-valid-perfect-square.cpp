class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        for(int i = 1; i <= num/i; i++){
            if(i * i == num){
                return true;
            }
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna