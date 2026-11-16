
class Solution {
    public String digitSum(String s, int k) {

        while (s.length() > k) {

            StringBuilder result = new StringBuilder();

            // Divide string into groups of k
            for (int i = 0; i < s.length(); i += k) {

                int sum = 0;

                // Calculate sum of digits in current group
                for (int j = i; j < Math.min(i + k, s.length()); j++) {
                    sum += s.charAt(j) - '0';
                }

                result.append(sum);
            }

            // Update original string
            s = result.toString();
        }

        return s;
    }
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna