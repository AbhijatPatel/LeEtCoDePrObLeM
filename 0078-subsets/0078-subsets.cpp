class Solution {
public:
void fun(int index,vector<int>& ds, vector<int>& nums,int n,vector<vector<int>>& ans){
    if(index == n){
        ans.push_back(ds);
        return;
    }
    fun(index+1,ds,nums,n,ans);

    ds.push_back(nums[index]);

    fun(index+1,ds,nums,n,ans);

    ds.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;

        fun(0,ds,nums,nums.size(),ans);

        return ans;
    }
};