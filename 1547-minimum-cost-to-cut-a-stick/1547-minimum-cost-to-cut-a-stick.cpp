class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& cuts, int i, int j) {
        if (i > j) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for (int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1]
                     + solve(cuts, i, k - 1)
                     + solve(cuts, k + 1, j);

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        dp.assign(m, vector<int>(m, -1));

        return solve(cuts, 1, m - 2);
    }
};