class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<vector<int>>& ans)
    {
        if(idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> st; // to track used elements at this level

        for(int i = idx; i < nums.size(); i++)
        {
            if(st.count(nums[i])) continue; // skip duplicates
            
            st.insert(nums[i]);

            swap(nums[idx], nums[i]);
            solve(nums, idx + 1, ans);
            swap(nums[idx], nums[i]); // backtrack
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0, ans);
        return ans;
    }
};
/*
                         [1,1,2]
                           |
        -------------------------------------
        |                 |                |
     pick 1(i=0)      pick 1(i=1) ❌ skip   pick 2(i=2)
        |                 |                |
     [1]              (skipped)          [2]
      |                                   |
  -----------                         -----------
  |         |                         |         |
pick1(i=1) pick2(i=2)          pick1(i=0) pick1(i=1) ❌ skip
  |         |                     |         |
 [1,1]    [1,2]                [2,1]     (skipped)
   |         |                   |
  [1,1,2]   [1,2,1]           [2,1,1]

   ✅         ✅                 ✅
*/