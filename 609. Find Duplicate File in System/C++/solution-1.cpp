class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentPaths;

        for (const string& path : paths) {
            stringstream ss(path);
            string word, root;
            int itr = 0;

            while (ss >> word) {
                if (itr++ == 0)
                    root = word;
                else {
                    int start = word.find("(");
                    int end = word.find(")", start);
                    string content = word.substr(start, end);
                    string path = word.substr(0, start);
                    contentPaths[content].push_back(root + "/" + path);
                }
            }
        }

        vector<vector<string>> result;

        for (const auto& [key, paths] : contentPaths)
            if (paths.size() > 1)
                result.push_back(move(paths));

        return result;
    }
};