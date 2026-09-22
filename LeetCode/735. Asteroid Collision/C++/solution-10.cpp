class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> answer;
        int size = asteroids.size();

        for (int i = 0; i < size; i++) {
            if (asteroids[i] > 0)
                answer.push_back(asteroids[i]);
            else if (answer.empty())
                answer.push_back(asteroids[i]);
            else if (answer.back() < 0)
                answer.push_back(asteroids[i]);
            else if (answer.back() > -asteroids[i])
                continue;
            else if (answer.back() == -asteroids[i])
                answer.pop_back();
            else {
                while (!answer.empty() && answer.back() > 0 &&
                       answer.back() < -asteroids[i]) {
                    answer.pop_back();
                }
                i = i - 1;
            }
        }

        return answer;
    }
};