class Solution {
public:
void fun(int index,int k,int n,vector<int> &ds,vector<vector<int>> &ans){
    if(k == 0 && n == 0){
        ans.push_back(ds);
        return;
    }
    if(k == 0 || n <= 0){
        return;
    }
    for(int i = index;i<=9;i++){

        if(i > n)
        break;

        ds.push_back(i);

        fun(i+1,k-1,n-i,ds,ans);
        
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        fun(1,k,n,ds,ans);

        return ans;
    }
};