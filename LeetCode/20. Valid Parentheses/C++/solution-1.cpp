class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parenMap = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        stack<char> st;

        for (const char& c : s)
            if (parenMap.count(c))
                if (!st.empty() && parenMap[c] == st.top())
                    st.pop();
                else
                    return false;
            else
                st.push(c);

        return st.empty();
    }
};