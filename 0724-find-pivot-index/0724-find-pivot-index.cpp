class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;

        //range-based for loop.
        //take every no. from nums one by one.
        for(int num : nums)
        total += num;

        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++){
            int rightSum = total - leftSum - nums[i];

            if(leftSum == rightSum)
            return i;

            leftSum += nums[i];
            //for no pivot exist
        }
        return -1;
    }
};