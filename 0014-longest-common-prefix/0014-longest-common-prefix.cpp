class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       sort(strs.begin(),strs.end());
       int p=strs.size();
       string f=strs[0],b=strs[p-1],result="";
       for(int i=0;i<f.size();i++)
       {
        if(f[i]==b[i])
        {
            result+=f[i];
        }
        else break;
       }
       return result;
        
    }
};