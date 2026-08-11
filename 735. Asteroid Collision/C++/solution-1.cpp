class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> answer;
        int size = asteroids.size();

        for (int i = 0; i < size; i++) {
            bool destroyed = false;
            if (asteroids[i] > 0)
                answer.push_back(asteroids[i]);
            else {
                while (!answer.empty() && answer.back() > 0 &&
                       answer.back() < -asteroids[i])
                    answer.pop_back();

                if (!answer.empty() && answer.back() > 0) {
                    if (answer.back() == -asteroids[i])
                        answer.pop_back();
                    destroyed = true;
                }
            }

            if (!destroyed && asteroids[i] < 0)
                answer.push_back(asteroids[i]);
        }

        return answer;
    }
};