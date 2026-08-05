class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<vector<long long>> left(n + 1), right(n + 1);

        // Generate subset sums for left half
        for (int mask = 0; mask < (1 << n); mask++) {
            long long sum = 0;
            int bits = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                    bits++;
                }
            }
            left[bits].push_back(sum);
        }

        // Generate subset sums for right half
        for (int mask = 0; mask < (1 << n); mask++) {
            long long sum = 0;
            int bits = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += nums[n + i];
                    bits++;
                }
            }
            right[bits].push_back(sum);
        }

        for (int i = 0; i <= n; i++)
            sort(right[i].begin(), right[i].end());

        long long total = 0;
        for (int x : nums)
            total += x;

        long long ans = LLONG_MAX;

        for (int lcnt = 0; lcnt <= n; lcnt++) {
            int rcnt = n - lcnt;

            for (long long lsum : left[lcnt]) {
                long long target = total / 2 - lsum;

                auto &vec = right[rcnt];
                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    long long s = lsum + *it;
                    ans = min(ans, llabs(total - 2 * s));
                }

                if (it != vec.begin()) {
                    --it;
                    long long s = lsum + *it;
                    ans = min(ans, llabs(total - 2 * s));
                }
            }
        }

        return (int)ans;
    }
};