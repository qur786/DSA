class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<vector<int>>> groupMap;
        int size = groupSizes.size();
        groupMap.reserve(500);
        vector<vector<int>> result;

        for (int i = 0; i < size; i++) {
            if (groupMap.count(groupSizes[i])) {
                if (groupMap[groupSizes[i]].back().size() == groupSizes[i])
                    groupMap[groupSizes[i]].push_back({i});
                else
                    groupMap[groupSizes[i]].back().push_back(i);
            } else
                groupMap[groupSizes[i]].push_back({i});
        }

        for (const auto& [group, arrays] : groupMap)
            result.insert(result.end(), make_move_iterator(arrays.begin()),
                          make_move_iterator(arrays.end()));
        return result;
    }
};