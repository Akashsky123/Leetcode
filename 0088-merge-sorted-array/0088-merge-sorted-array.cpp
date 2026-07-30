class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //method1

      //  vector<int>ans(m+n);
      //  for(int i=0;i<m;i++)
      //  {
      //      ans[i]=nums1[i];
      //  }
      //  for(int j=0;j<n;j++)
      //  {
      //      ans[m+j]=nums2[j];
      //  }
      
       // sort(ans.begin(),ans.end());
      // for(int i=0;i<m+n;i++)
       // {
       //     nums1[i] = ans[i];
        //}

        //method-2

        for (int p = 0, q = m; p<n; p++)
      {
        nums1[q] = nums2[p];
         q++;
     }
     sort(nums1.begin(),nums1.end());

        
    }
};