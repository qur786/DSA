class Solution {
public:
    string removeDuplicates(string s) {
        string output;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            if (output.empty() || output.back() != s[i])
                output.push_back(s[i]);
            else {
                while (!output.empty() && output.back() == s[i])
                    output.pop_back();
            }
        }

        return output;
    }
};