class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {

            // Traverse the top row (left -> right)
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[top][col]);
            }
            top++;

            // Traverse the right column (top -> bottom)
            for (int row = top; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            right--;

            // Traverse the bottom row (right -> left)
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            // Traverse the left column (bottom -> top)
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        }

        return result;
    }
};