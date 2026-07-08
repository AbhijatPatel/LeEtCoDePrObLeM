class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        freq[0] = 1;

        int currentSum = 0;
        int answer = 0;

        for (int num : nums) {

            currentSum += num;

            if (freq.find(currentSum - k) != freq.end()) {
                answer += freq[currentSum - k];
            }

            freq[currentSum]++;
        }

        return answer;
    }
};