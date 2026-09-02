class Solution {
public:
    int totalFruit(vector<int>& fruits){
        int left = 0, right = 0;
        int maxLen = 0;
        int k = 2;
        map<int,int> mp;
        int n = fruits.size();

        while(right < n){
            mp[fruits[right]]++;

            if(mp.size() > k){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            if(mp.size() <= k){
                maxLen = max(maxLen,right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};