class Solution {
public:
     bool ispalind(string s)
     {
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s==s2;
     }
     void Solve(string s,vector<string>&prtn,vector<vector<string>>&ans)
     {
        if(s.size()==0)
        {
            ans.push_back(prtn);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            string part=s.substr(0,i+1);
            if(ispalind(part))
            {
                prtn.push_back(part);
                Solve(s.substr(i+1),prtn,ans);
                prtn.pop_back();

            }
        }

     }
    vector<vector<string>> partition(string s) {

        vector<vector<string>>ans;
        vector<string>prtn;
        Solve(s,prtn,ans);
        return ans;
    }
};