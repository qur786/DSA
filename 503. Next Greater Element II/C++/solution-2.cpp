class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int size = nums.size();
        vector<int> answer(size, -1);

        for (int itr = 0; itr < 2; itr++) {
            for (int i = 0; i < size; i++) {
                while (!st.empty() && nums[i] > nums[st.top()]) {
                    answer[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }

        return answer;
    }
};