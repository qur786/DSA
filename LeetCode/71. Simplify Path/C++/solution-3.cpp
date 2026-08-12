class Solution {
public:
    string simplifyPath(string path) {
        vector<string> paths;
        stringstream ss(path);
        string word;

        while (getline(ss, word, '/')) {
            if (word.empty() || word == ".")
                continue;
            else if (word == "..") {
                if (!paths.empty())
                    paths.pop_back();
                continue;
            }
            paths.push_back(word);
        }

        string output;

        for (const string& p : paths) {
            output.append("/");
            output.append(p);
        }

        return output.empty() ? "/" : output;
    }
};