class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = 1, hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        // Remove duplicate coin values
        sort(coins.begin(), coins.end());
        coins.erase(unique(coins.begin(), coins.end()), coins.end());

        auto lcm = [](long long a, long long b) -> long long {
            return a / std::gcd(a, b) * b;
        };

        // Count how many positive integers <= x are divisible by
        // at least one coin.
        auto count = [&](long long x) -> long long {
            long long ans = 0;
            int n = coins.size();

            // Inclusion-exclusion over all subsets
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long multiple = 1;
                bool valid = true;
                int bits = 0;

                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        ++bits;
                        multiple = lcm(multiple, coins[i]);

                        if (multiple > x) {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid) continue;

                long long cnt = x / multiple;

                if (bits & 1)
                    ans += cnt;
                else
                    ans -= cnt;
            }

            return ans;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};