class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        vector<bool> visited(size, false);
        vector<int> answer;
        answer.reserve(size);
        queue<int> nodes;
        nodes.push(0);
        visited[0] = true;

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();

            answer.push_back(front);

            for (int child : rooms[front]) {
                if (!visited[child]) {
                    visited[child] = true;
                    nodes.push(child);
                }
            }
        }

        bool result = none_of(visited.begin(), visited.end(),
                              [](bool value) { return !value; });

        return result;
    }
};