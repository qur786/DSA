class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string word, simplifiedPath;
        stack<string> paths, reversePaths;

        while (getline(ss, word, '/')) {
            if (word.size() == 0)
                continue;
            else if (word == ".")
                continue;
            else if (word == "..") {
                if (!reversePaths.empty())
                    reversePaths.pop();
            } else
                reversePaths.push(word);
        }

        if (reversePaths.empty())
            return "/";

        while (!reversePaths.empty()) {
            paths.push(reversePaths.top());
            reversePaths.pop();
        }

        while (!paths.empty()) {
            simplifiedPath.append("/");
            simplifiedPath.append(paths.top());
            paths.pop();
        }

        return simplifiedPath;
    }
};