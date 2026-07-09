class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
       vector<int> num3(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), num3.begin());

        int m=num3.size();
        sort(num3.begin(),num3.end());
        if(m%2==0)
        {
            return (num3[m/2-1]+num3[m/2])/2.0;
        }
        else
        return num3[m/2];
    }
};