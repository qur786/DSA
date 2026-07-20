class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int size = temperatures.size();
        vector<int> answer(size, 0);

        for (int i = 0; i < size; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                answer[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return answer;
    }
};