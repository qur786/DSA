class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> values;
        int size = asteroids.size();
        values.reserve(size);

        for (int i = 0; i < size; i++) {
            if (asteroids[i] > 0) {
                values.push_back(asteroids[i]);
            } else {
                if (values.empty())
                    values.push_back(asteroids[i]);
                else if (values.back() < 0)
                    values.push_back(asteroids[i]);
                else if (values.back() > -asteroids[i])
                    continue;
                else if (values.back() == -asteroids[i])
                    values.pop_back();
                else {
                    while (!values.empty() && values.back() > 0 &&
                           values.back() < -asteroids[i])
                        values.pop_back();

                    i = i - 1;
                }
            }
        }

        return values;
    }
};