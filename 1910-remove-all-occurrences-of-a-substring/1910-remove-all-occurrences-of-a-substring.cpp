class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        for(auto a:s)
        {
            ans.push_back(a);
            if(ans.size()>=part.size()&& ans.substr(ans.size()-part.size())==part)
            {
                int x=part.size();
                while(x--)
                {
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};