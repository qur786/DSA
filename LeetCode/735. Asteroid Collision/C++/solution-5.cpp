class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int size = asteroids.size();
        vector<int> st;

        for (int i = 0; i < size; i++) {
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            } else {
                if (st.empty())
                    st.push_back(asteroids[i]);
                else if (st.back() < 0)
                    st.push_back(asteroids[i]);
                else if (st.back() > -asteroids[i])
                    continue;
                else if (st.back() == -asteroids[i])
                    st.pop_back();
                else {
                    while (!st.empty() && st.back() > 0 &&
                           st.back() < -asteroids[i])
                        st.pop_back();

                    i = i - 1;
                }
            }
        }

        return st;
    }
};