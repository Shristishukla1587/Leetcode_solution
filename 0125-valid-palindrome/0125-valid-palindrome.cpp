class Solution {
public:
    bool isPalindrome(string s) {
        string k = "";
        for(char ch: s){
           if(isalnum(ch)) {
            k += tolower(ch);
            }
        }
        string c = k;
        reverse(c.begin(), c.end());
        if(c == k){
            return true;
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna