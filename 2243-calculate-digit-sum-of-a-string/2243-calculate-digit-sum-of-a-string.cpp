
class Solution {
public:
    string digitSum(string s, int k) {

        while (s.length() > k) {

            string result = "";

            // Divide string into groups of k
            for (int i = 0; i < s.length(); i += k) {

                int sum = 0;

                // Calculate sum of digits in current group
                for (int j = i; j < min(i + k, (int)s.length()); j++) {
                    sum += s[j] - '0';
                }

                result += to_string(sum);
            }

            // Update original string
            s = result;
        }

        return s;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna