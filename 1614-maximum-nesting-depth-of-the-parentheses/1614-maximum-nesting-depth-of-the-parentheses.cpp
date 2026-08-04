class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int maxDepth = 0;

        for(int i=0;i<s.size();i++){
            if(s[i] == ('(')){
                st.push(s[i]);

                maxDepth = max(maxDepth,(int)st.size());
            }
            else if(s[i] == (')')){
                st.pop();
            }
        }
        return maxDepth;
    }
};