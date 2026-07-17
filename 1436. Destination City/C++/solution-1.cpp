class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> pathMap;

        for (const auto& path : paths) {
            pathMap[path[0]] = path[1];
        }
        for (const auto& [source, dest] : pathMap) {
            if (!pathMap.count(dest))
                return dest;
        }
        return "";
    }
};