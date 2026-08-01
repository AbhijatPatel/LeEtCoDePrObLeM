class Solution {
public:
int maxRow(vector<vector<int>> &mat, int col)
{
    int row = 0;

    for (int i = 1; i < mat.size(); i++)
    {
        if (mat[i][col] > mat[row][col])
        {
            row = i;
        }
    }

    return row;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int row = maxRow(mat, mid);

        int left;
        if (mid == 0)
            left = -1;
        else
            left = mat[row][mid - 1];

        int right;
        if (mid == m - 1)
            right = -1;
        else
            right = mat[row][mid + 1];

        int curr = mat[row][mid];

        if (curr > left && curr > right)
        {
            return {row, mid};
        }
        else if (left > curr)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat =
    {
        {10,20,15,2},
        {21,30,14,5},
        {7,16,32,4}
    };

    vector<int> ans = findPeakGrid(mat);

    cout << "Peak Position = (" << ans[0] << ", " << ans[1] << ")" << endl;
    cout << "Peak Value = " << mat[ans[0]][ans[1]];

    return 0; 
    }
};