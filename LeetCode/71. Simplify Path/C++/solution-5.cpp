class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> tokens;

        while (getline(ss, token, '/')) {
            if (token.empty())
                continue;
            if (token == ".")
                continue;
            if (token == "..") {
                if (!tokens.empty())
                    tokens.pop_back();
            } else
                tokens.push_back(token);
        }

        if (tokens.empty())
            return "/";
        string answer;

        for (const string& tok : tokens) {
            answer.append("/");
            answer.append(tok);
        }

        return answer;
    }
};