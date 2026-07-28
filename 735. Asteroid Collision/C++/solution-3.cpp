class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int size = asteroids.size();
        vector<int> savedAsteroids;
        savedAsteroids.reserve(size);

        for (int i = 0; i < size; i++) {
            if (asteroids[i] > 0)
                savedAsteroids.push_back(asteroids[i]);
            else {
                if (savedAsteroids.empty())
                    savedAsteroids.push_back(asteroids[i]);
                else if (savedAsteroids.back() < 0)
                    savedAsteroids.push_back(asteroids[i]);
                else if (savedAsteroids.back() > -asteroids[i])
                    continue;
                else if (savedAsteroids.back() == -asteroids[i])
                    savedAsteroids.pop_back();
                else {
                    while (!savedAsteroids.empty() &&
                           savedAsteroids.back() > 0 &&
                           savedAsteroids.back() < -asteroids[i])
                        savedAsteroids.pop_back();
                    i--;
                }
            }
        }

        return savedAsteroids;
    }
};