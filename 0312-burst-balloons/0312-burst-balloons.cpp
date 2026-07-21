class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // Add virtual balloons with value 1
        vector<int> arr(n + 2);
        arr[0] = 1;
        arr[n + 1] = 1;

        for (int i = 0; i < n; i++)
            arr[i + 1] = nums[i];

        int m = n + 2;
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // length = interval length
        for (int len = 2; len < m; len++) {
            for (int left = 0; left + len < m; left++) {
                int right = left + len;

                for (int k = left + 1; k < right; k++) {
                    dp[left][right] = max(
                        dp[left][right],
                        dp[left][k] +
                        dp[k][right] +
                        arr[left] * arr[k] * arr[right]
                    );
                }
            }
        }

        return dp[0][m - 1];
    }
};