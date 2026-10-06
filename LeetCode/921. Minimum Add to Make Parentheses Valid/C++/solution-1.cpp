class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            if (s[i] == '(')
                st.push(s[i]);
            else {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }

        return st.size();
    }
};