class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> paths;

        while (getline(ss, token, '/')) {
            if (token.empty())
                continue;
            else if (token == ".")
                continue;
            else if (token == "..") {
                if (!paths.empty())
                    paths.pop_back();
            } else {
                paths.push_back(token);
            }
        }

        if (paths.empty())
            return "/";

        string answer;

        for (int i = 0; i < paths.size(); i++) {
            answer.append("/");
            answer.append(paths[i]);
        }

        return answer;
    }
};