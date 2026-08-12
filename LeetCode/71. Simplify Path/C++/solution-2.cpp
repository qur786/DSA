class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string word, simplifiedPath;
        vector<string> directories;

        while (getline(ss, word, '/')) {
            if (word.size() == 0)
                continue;
            else if (word == ".")
                continue;
            else if (word == "..") {
                if (!directories.empty())
                    directories.pop_back();
            } else
                directories.push_back(word);
        }

        if (directories.empty())
            return "/";

        for (const auto& dir : directories) {
            simplifiedPath.push_back('/');
            simplifiedPath.append(dir);
        }

        return simplifiedPath;
    }
};