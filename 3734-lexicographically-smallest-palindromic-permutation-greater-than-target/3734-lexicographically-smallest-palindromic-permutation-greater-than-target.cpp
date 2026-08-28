class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // Check whether palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        // cnt now represents the available characters
        // for both sides.
        if (n & 1)
            cnt[mid - 'a']--;

        /*
            Try to make the left half exactly equal
            to target's left half.
        */
        for (int i = 0; i < m; i++) {
            cnt[target[i] - 'a'] -= 2;
        }

        auto valid = [&]() {
            for (int x : cnt) {
                if (x < 0)
                    return false;
            }
            return true;
        };

        /*
            Case 1:
            target's left half can be used exactly.

            Then the palindrome has the same left half
            as target, so compare the right half.
        */
        if (valid()) {
            string left = target.substr(0, m);
            string right;

            if (n & 1)
                right += mid;

            for (int i = m - 1; i >= 0; i--)
                right += left[i];

            if (right > target.substr(m))
                return left + right;
        }

        /*
            Case 2:
            Find the rightmost position in the left half
            that we can increase.
        */
        for (int i = m - 1; i >= 0; i--) {

            int cur = target[i] - 'a';

            // Restore this pair because we are going
            // to change target[i].
            cnt[cur] += 2;

            if (!valid())
                continue;

            // Try the smallest character greater than cur.
            for (int c = cur + 1; c < 26; c++) {

                if (cnt[c] < 2)
                    continue;

                // Use this character as the new pair.
                cnt[c] -= 2;

                string ans = target.substr(0, i);
                ans += char('a' + c);

                // Fill the remaining left half
                // with the smallest possible characters.
                for (int x = 0; x < 26; x++) {
                    while (cnt[x] >= 2) {
                        ans += char('a' + x);
                        cnt[x] -= 2;
                    }
                }

                // Mirror
                string right = ans;
                reverse(right.begin(), right.end());

                ans += (n & 1 ? string(1, mid) : "");
                ans += right;

                return ans;
            }
        }

        return "";
    }
};