class Solution {
public:
    void solve(vector<int>& candidates, int target, int idx,
               vector<int>& curr, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            // Pruning
            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // Move to next index (each element used once)
            solve(candidates, target - candidates[i], i + 1, curr, ans);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, target, 0, curr, ans);

        return ans;
    }
};