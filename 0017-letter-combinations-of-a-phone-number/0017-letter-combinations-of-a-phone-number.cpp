class Solution {
public:

    void fun(int ind, string digits, vector<string>& ans,
             string s, vector<string>& mp) {

        
        if (ind == digits.size()) {
            ans.push_back(s);
            return;
        }

        
        int i = digits[ind] - '0';
        string letters = mp[i];

        
        for (char c : letters) {
            s.push_back(c);

            fun(ind + 1, digits, ans, s, mp);

            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if (digits.empty())
            return ans;

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        fun(0, digits, ans, "", mp);

        return ans;
    }
};