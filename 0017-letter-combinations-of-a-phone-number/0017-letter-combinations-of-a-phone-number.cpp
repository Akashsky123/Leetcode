class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        vector<string> result;
        string current;
        
        backtrack(digits, 0, mapping, current, result);
        return result;
    }
    
    void backtrack(string& digits, int index, vector<string>& mapping, 
                   string& current, vector<string>& result) {
        
        // Base case
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        string letters = mapping[digits[index] - '0'];
        
        for (char ch : letters) {
            current.push_back(ch);        // choose
            backtrack(digits, index + 1, mapping, current, result); // explore
            current.pop_back();           // un-choose
        }
    }
};
