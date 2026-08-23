class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string c;

        int i = 0;

        while(i < word1.size() && i < word2.size()) {
            c.push_back(word1[i]);
            c.push_back(word2[i]);
            i++;
        }

        while(i < word1.size()) {
            c.push_back(word1[i]);
            i++;
        }

        while(i < word2.size()) {
            c.push_back(word2[i]);
            i++;
        }

        return c;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna