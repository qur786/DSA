class Solution {
public:
    string simplifyPath(string path) {
        string word;
        vector<string> paths;
        stringstream ss(path);

        while (getline(ss, word, '/')) {
            if (word.empty() || word == ".")
                continue;
            else if (word == "..") {
                if (!paths.empty())
                    paths.pop_back();
            } else
                paths.push_back(word);
        }

        if (paths.empty())
            return "/";

        string result;

        for (int i = 0; i < paths.size(); i++) {
            result.push_back('/');
            result.append(paths[i]);
        }

        return result;
    }
};