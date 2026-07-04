class Solution {
public:
    bool isAnagram(string s, string t) {
        string n = s;
        sort(n.begin(), n.end());
        string m = t;
        sort(m.begin(),m.end());
        if(m==n)
        {
            return true;
        }
        return false;
        
    }
};