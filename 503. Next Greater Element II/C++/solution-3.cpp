class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        stack<int> st;
        vector<int> result(size, -1);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < size; j++) {
                while (!st.empty() && nums[st.top()] < nums[j]) {
                    result[st.top()] = nums[j];
                    st.pop();
                }
                st.push(j);
            }
        }
        return result;
    }
};