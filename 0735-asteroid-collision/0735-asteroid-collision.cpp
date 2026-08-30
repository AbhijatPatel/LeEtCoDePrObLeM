class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> st;

        for (int i = 0; i < asteroids.size(); i++) {

            int current = asteroids[i];
            bool destroyed = false;

            while (!st.empty() && st.back() > 0 && current < 0) {

                if (st.back() < -current) {
                    st.pop_back();
                }
                else if (st.back() == -current) {
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(current);
            }
        }

        return st;
    }
};