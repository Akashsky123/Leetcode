class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>freq(n*n+1,0);
        for(auto & row:grid)
           for(int x:row)
              freq[x]++;
        int repeated,missing;
        for(int i=0;i<=n*n;i++)
        {
            if(freq[i]==2)
            repeated=i;
            if(freq[i]==0)
            missing=i;
        }
        return{repeated,missing};
    }
};