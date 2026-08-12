class Solution {
public:
    vector<int> getNextGreaterElement(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, -1);
        stack<int> st;
        for (int i = 0; i < size; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                result[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < size; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                result[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        return getNextGreaterElement(nums);
    }
};