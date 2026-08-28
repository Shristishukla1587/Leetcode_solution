class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Step 1: Count frequency
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Step 2: Check whether palindrome is possible
        int odd = 0;
        int mid = -1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                odd++;
                mid = i;
            }
        }

        // More than one odd frequency -> impossible
        if (odd > 1) {
            return "";
        }

        // Step 3: Only half of each frequency
        for (int i = 0; i < 26; i++) {
            freq[i] /= 2;
        }

        int half = n / 2;

        string left = "";

        /*
            First try to make the left half
            exactly equal to target's left half.
        */

        int pos = 0;

        while (pos < half) {

            int ch = target[pos] - 'a';

            // We don't have this character
            if (freq[ch] == 0) {
                break;
            }

            left.push_back(target[pos]);
            freq[ch]--;

            pos++;
        }

        /*
            Case 1:
            We successfully matched the entire left half.
        */

        if (pos == half) {

            string right = left;

            reverse(right.begin(), right.end());

            string ans = left;

            if (n % 2 == 1) {
                ans += char('a' + mid);
            }

            ans += right;

            // Equal or greater?
            if (ans > target) {
                return ans;
            }
        }

        /*
            Now we need to make the answer
            slightly bigger than target.

            We start from the current position
            and try a bigger character.

            If impossible, move one position back.
        */

        while (true) {

            /*
                Try to increase current position.
            */

            if (pos < half) {

                int targetChar = target[pos] - 'a';

                // Try characters strictly greater than target[pos]
                for (int ch = targetChar + 1; ch < 26; ch++) {

                    if (freq[ch] == 0) {
                        continue;
                    }

                    // Choose this character
                    left.push_back(char('a' + ch));
                    freq[ch]--;

                    /*
                        After making the answer greater,
                        remaining characters should be placed
                        in the smallest possible order.
                    */

                    string remaining = "";

                    for (int c = 0; c < 26; c++) {
                        while (freq[c] > 0) {
                            remaining.push_back(char('a' + c));
                            freq[c]--;
                        }
                    }

                    string finalLeft = left + remaining;

                    /*
                        Construct palindrome.
                    */

                    string ans = finalLeft;

                    if (n % 2 == 1) {
                        ans += char('a' + mid);
                    }

                    string rev = finalLeft;
                    reverse(rev.begin(), rev.end());

                    ans += rev;

                    return ans;
                }
            }

            /*
                We couldn't increase current position.

                Move one position backward.
            */

            if (pos == 0) {
                return "";
            }

            pos--;

            /*
                Remove target[pos] from left
                and put it back into freq.
            */

            int ch = target[pos] - 'a';

            freq[ch]++;
            left.pop_back();
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna