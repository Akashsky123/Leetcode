class Solution {
public:
    bool canDistribute(vector<int>& candies, long long k, long long mid) {
        long long count = 0;

        for (int i = 0; i < candies.size(); i++) {
            count += candies[i] / mid;

            if (count >= k) return true; // early exit
        }

        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long long high = 0;

        for (int c : candies) {
            high = max(high, (long long)c);
        }

        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid == 0) break; // safety

            if (canDistribute(candies, k, mid)) {
                ans = mid;
                low = mid + 1;  // maximize
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};