class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        stack<int> st;

        int maxArea = 0;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                   (i == n || heights[st.top()] > heights[i])) {

                int element = heights[st.top()];
                st.pop();

                int nse = i;

                int pse;

                if (st.empty()) {
                    pse = -1;
                }
                else {
                    pse = st.top();
                }

                int width = nse - pse - 1;

                int area = element * width;

                maxArea = max(maxArea, area);
            }

            if (i < n) {
                st.push(i);
            }
        }

        return maxArea;
    }
};