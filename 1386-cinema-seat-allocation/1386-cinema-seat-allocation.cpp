class Solution {
public:
        int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> rows;

        // Store reserved seats as a bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            rows[row] |= (1 << col);
        }

        // Initially, every row can accommodate 2 groups
        int ans = 2 * (n - rows.size());

        // Check rows having reservations
        for (auto &[row, mask] : rows) {

            bool left = true;
            bool middle = true;
            bool right = true;

            // 2,3,4,5
            for (int seat = 2; seat <= 5; seat++) {
                if (mask & (1 << seat)) {
                    left = false;
                    break;
                }
            }

            // 4,5,6,7
            for (int seat = 4; seat <= 7; seat++) {
                if (mask & (1 << seat)) {
                    middle = false;
                    break;
                }
            }

            // 6,7,8,9
            for (int seat = 6; seat <= 9; seat++) {
                if (mask & (1 << seat)) {
                    right = false;
                    break;
                }
            }

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};