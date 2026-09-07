class Solution {
public:
// void fun(int index,string &s,string &ds,set<string> &st){
//     if(index == s.size()){
//         if(!ds.empty()){
//             st.insert(ds);
//         }
//         return;
//     }

//     fun(index+1,s,ds,st);

//     ds.push_back(s[index]);

//     fun(index+1,s,ds,st);

//     ds.pop_back();
// }
//     int distinctSubseqII(string s) {
//         set<string> st;
//         string ds = "";
        
//         fun(0,s,ds,st);
//         return st.size();
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(26, 0);

        long long total = 0;

        for (char c : s) {
            int x = c - 'a';

            long long newSubseq = (total + 1) % MOD;

            total = (total + newSubseq - dp[x] + MOD) % MOD;

            dp[x] = newSubseq;
        }

        return total;
    }
};