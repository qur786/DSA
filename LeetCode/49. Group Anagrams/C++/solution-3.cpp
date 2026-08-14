class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagrams;

        for (const string str : strs) {
            string sortStr = str;
            sort(sortStr.begin(), sortStr.end());
            anagrams[sortStr].push_back(str);
        }

        for (const auto& [key, strings] : anagrams) {
            result.push_back(move(strings));
        }

        return result;
    }
};