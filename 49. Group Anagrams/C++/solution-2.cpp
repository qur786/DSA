class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anaMap;
        vector<vector<string>> result;

        for (const auto& str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            anaMap[temp].push_back(str);
        }

        for (const auto& [key, anagrams] : anaMap)
            result.push_back(anagrams);

        return result;
    }
};