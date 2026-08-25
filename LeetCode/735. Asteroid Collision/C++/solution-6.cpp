class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> survived;
        int size = asteroids.size();
        survived.reserve(size);

        for (int i = 0; i < size; i++) {
            if (asteroids[i] > 0)
                survived.push_back(asteroids[i]);
            else if (survived.empty())
                survived.push_back(asteroids[i]);
            else if (survived.back() < 0)
                survived.push_back(asteroids[i]);
            else if (survived.back() > -asteroids[i])
                continue;
            else if (survived.back() == -asteroids[i])
                survived.pop_back();
            else {
                while (!survived.empty() && survived.back() > 0 &&
                       survived.back() < -asteroids[i]) {
                    survived.pop_back();
                }
                i = i - 1;
            }
        }

        return survived;
    }
};