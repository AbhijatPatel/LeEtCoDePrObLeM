class Solution {
public:
void fun(int index,vector<int> &nums,int n, vector<int> &ds,vector<vector<int>> &  ans){
    ans.push_back(ds);
    for(int i=index; i<n; i++){
        if(i>index && nums[i] == nums[i-1])
        continue;
        ds.push_back(nums[i]);

        fun(i+1,nums,n,ds,ans);

        ds.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(),nums.end());

      vector<vector<int>> ans;
      vector<int> ds;

      fun(0,nums,nums.size(),ds,ans);
      return ans;  
    }
};