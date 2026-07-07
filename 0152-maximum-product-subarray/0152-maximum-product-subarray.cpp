class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int ans = nums[0];

        for(int i=1;i<nums.size();i++){

            int current = nums[i];
            int oldMax = maxEnding;
            int oldMin = minEnding;

            maxEnding = max({current,current*oldMax,current*oldMin});

            minEnding = min({current,current*oldMax,current*oldMin});

            ans = max(ans,maxEnding);
        }
        return ans;
    }
};