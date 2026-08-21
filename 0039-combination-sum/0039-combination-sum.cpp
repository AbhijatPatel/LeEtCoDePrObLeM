class Solution {
public:
    
void fun(int index, vector<int>& candidates,int n,int currSum, int target,vector<int>& ds, vector<vector<int>>& ans) {

    // Target reached
    if (target == currSum) {
        ans.push_back(ds);
        return;
    }

    // Out of elements
    if (index == candidates.size()) {
        return;
    }

    // Take current element
    if (currSum + candidates[index] <= target) {

        ds.push_back(candidates[index]);

        // index stays same because
        // we can use the same element again
        fun(index, candidates,n,currSum + candidates[index],
target,ds, ans);

        // Backtrack
        ds.pop_back();
    }

    // Not take current element
    fun(index + 1, candidates,n,currSum, target, ds, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<vector<int>> ans;
    vector<int> ds;

    fun(0, candidates, candidates.size(),0,target, ds, ans);

    return ans;
}

};