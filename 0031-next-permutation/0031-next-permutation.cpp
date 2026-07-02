class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int last = n-1;
        // int val = last;
        while(last>=1){
            if(nums[last-1]<nums[last]){
                int val = last;
                while(val<n-1 && (nums[val+1]>nums[last-1])){
                    val++;
                }
                
                swap(nums[last-1],nums[val]);
                break;
            }
            
            last--;
        }
        sort(nums.begin()+last,nums.end());
        
    }
};