class Solution {
public:
    void parmu(vector<int>&nums,int idx,vector<vector<int>>&ans)
    {
        if(idx==nums.size())
        {
            ans.push_back({nums});
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            parmu(nums,idx+1,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        parmu(nums,0,ans);
        return ans;
        
    }
};
  /*
                          [1,2,3] (idx=0)
                    /          |           \
             swap(0,0)   swap(0,1)   swap(0,2)
                |            |            |
            [1,2,3]      [2,1,3]      [3,2,1]
             idx=1         idx=1         idx=1
            /    \        /    \        /    \
     swap(1,1) swap(1,2) ...   ...    ...    ...
        |          |    
    [1,2,3]    [1,3,2]
     idx=2       idx=2
     /   \        /   \
 [1,2,3] [1,2,3] [1,3,2] [1,3,2]
  (ans)             (ans)
*/