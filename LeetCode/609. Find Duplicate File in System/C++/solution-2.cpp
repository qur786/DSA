class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> pathMap;

        for (const string& path : paths) {
            stringstream ss(path);
            string word;
            ss >> word;
            string root = word;

            while (ss >> word) {
                auto openIt = word.find('(');
                auto closeIt = word.find(')');
                string p = word.substr(0, openIt);
                string content = word.substr(openIt, closeIt);

                pathMap[content].push_back(root + "/" + p);
            }
        }

        for (const auto& [content, path] : pathMap)
            if (path.size() > 1)
                result.push_back(move(path));

        return result;
    }
};