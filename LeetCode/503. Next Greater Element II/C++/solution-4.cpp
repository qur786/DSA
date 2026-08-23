class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> answer(size, -1);
        stack<int> st;

        for (int count = 0; count < 2; count++) {
            for (int i = 0; i < size; i++) {
                while (!st.empty() && (nums[i] > nums[st.top()])) {
                    answer[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }

        return answer;
    }
};