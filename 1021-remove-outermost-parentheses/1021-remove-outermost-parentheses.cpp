class Solution {
public:
    string removeOuterParentheses(string s) {
    string ans = "";
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(ch == '('){
            if(cnt > 0)
            ans += ch;
            cnt++;
        }
        else{
            cnt--;
            if(cnt > 0)
            ans += ch;
        }
    }
    return ans;
    }
};