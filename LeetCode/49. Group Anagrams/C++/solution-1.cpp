class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram;
        vector<vector<string>> result;

        for (const string& str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            anagram[s].push_back(str);
        }

        for (const auto [key, ans] : anagram) {
            result.push_back(ans);
        }

        return result;
    }
};