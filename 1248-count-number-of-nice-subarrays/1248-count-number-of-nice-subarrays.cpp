class Solution {
public:
int atMost(vector<int>& nums, int goal) {
    if (goal < 0) {
        return 0;
    }

    int left = 0;
    int sum = 0;
    int ans = 0;

    for (int right = 0; right < nums.size(); right++) {

        sum += nums[right] % 2;

        while (sum > goal) {
            sum -= nums[left] % 2;
            left++;
        }

        ans += right - left + 1;
    }

    return ans;
}

int numberOfSubarrays(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};