class Solution {
public:
    int characterReplacement(string s, int k) {
                int l = 0;
        int maxLen = 0, maxFreq = 0;
        int n = s.size();

        int freq[26] = {0};

        for (int r = 0; r < n; r++) {
            freq[s[r] - 'A']++;

            for (int i = 0; i < 26; i++) {
                maxFreq = max(maxFreq, freq[i]);
            }

            if ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;

                maxFreq = 0;

                for (int i = 0; i < 26; i++) {
                    maxFreq = max(maxFreq, freq[i]);
                }
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};