class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        stack<int> st;
        long long ans = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int j = st.top();
                st.pop();

                int left = st.empty() ? 0 : st.top() + 1;
                int right = i - 1;

                long long sum = pre[right + 1] - pre[left];
                ans = max(ans, sum * nums[j]);
            }

            st.push(i);
        }

        return ans % 1000000007;
    }
};