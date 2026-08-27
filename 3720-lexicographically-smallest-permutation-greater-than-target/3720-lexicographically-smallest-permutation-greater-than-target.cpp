class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
                int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            int freq[26] = {};

            for (char c : s)
                freq[c - 'a']++;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (freq[x] == 0) {
                    possible = false;
                    break;
                }

                freq[x]--;
            }

            if (!possible)
                continue;

            int cur = target[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (freq[c] == 0)
                    continue;

                string ans = target.substr(0, i);
                ans += char('a' + c);
                freq[c]--;

                for (int x = 0; x < 26; x++) {
                    while (freq[x] > 0) {
                        ans += char('a' + x);
                        freq[x]--;
                    }
                }

                return ans;
            }
        }

        return "";


    }
};