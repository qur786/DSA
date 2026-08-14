class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> cityMap;

        for (const auto& path : paths) {
            cityMap[path[0]] = path[1];
        }

        for (const auto& [origin, destination] : cityMap) {
            if (!cityMap.count(destination))
                return destination;
        }

        return "";
    }
};