class Solution {
public:
    vector<vector<int>> jobs;
    vector<int> dp;

    int solve(int i) {
        if (i >= jobs.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Find the first job whose start time >= current job's end time
        int next = lower_bound(
            jobs.begin(), jobs.end(), jobs[i][1],
            [](const vector<int>& job, int endTime) {
                return job[0] < endTime;
            }) - jobs.begin();

        int take = jobs[i][2] + solve(next);
        int skip = solve(i + 1);

        return dp[i] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        dp.assign(n, -1);

        return solve(0);
    }
};