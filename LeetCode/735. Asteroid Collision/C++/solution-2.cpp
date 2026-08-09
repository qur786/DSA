class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int size = asteroids.size();
        vector<int> result;
        result.reserve(size);

        for (int i = 0; i < size; i++) {
            if (asteroids[i] > 0)
                result.push_back(asteroids[i]);
            else {
                if (result.empty())
                    result.push_back(asteroids[i]);
                else if (result.back() < 0)
                    result.push_back(asteroids[i]);
                else if (result.back() > -asteroids[i])
                    continue;
                else if (result.back() == -asteroids[i]) {
                    result.pop_back();
                    continue;
                } else {
                    while (!result.empty() && result.back() > 0 &&
                           result.back() < -asteroids[i])
                        result.pop_back();
                    i--;
                }
            }
        }

        return result;
    }
};