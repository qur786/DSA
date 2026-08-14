class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groupMap;
        vector<vector<int>> result;
        int size = groupSizes.size();

        for (int i = 0; i < size; i++) {
            groupMap[groupSizes[i]].push_back(i);

            if (groupMap[groupSizes[i]].size() == groupSizes[i])
                result.push_back(move(groupMap[groupSizes[i]]));
        }

        return result;
    }
};