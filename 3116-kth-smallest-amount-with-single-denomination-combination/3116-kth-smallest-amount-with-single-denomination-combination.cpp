class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    // Count numbers <= x that are divisible by at least one coin
    long long count(long long x, vector<int>& coins) {
        long long ans = 0;
        int n = coins.size();

        // Inclusion-exclusion
        for (int mask = 1; mask < (1 << n); mask++) {
            long long L = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    L = lcm(L, coins[i]);

                    // L already exceeds x, so this subset contributes 0
                    if (L > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            long long cur = x / L;

            if (bits & 1)
                ans += cur;
            else
                ans -= cur;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = 1;
        long long hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (count(mid, coins) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna