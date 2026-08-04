class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> survivedAsteroids;
        int size = asteroids.size();

        for (int i = 0; i < size; i++) {
            if (asteroids[i] > 0) {
                survivedAsteroids.push_back(asteroids[i]);
            } else {
                if (survivedAsteroids.empty())
                    survivedAsteroids.push_back(asteroids[i]);
                else if (survivedAsteroids.back() < 0)
                    survivedAsteroids.push_back(asteroids[i]);
                else if (survivedAsteroids.back() > -asteroids[i])
                    continue;
                else if (survivedAsteroids.back() == -asteroids[i])
                    survivedAsteroids.pop_back();
                else {
                    while (!survivedAsteroids.empty() &&
                           survivedAsteroids.back() > 0 &&
                           survivedAsteroids.back() < -asteroids[i])
                        survivedAsteroids.pop_back();
                    i = i - 1;
                }
            }
        }

        return survivedAsteroids;
    }
};