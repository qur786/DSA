class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        int size2 = nums2.size(), size1 = nums1.size();
        stack<int> st;

        vector<int> result(size1, -1);

        for (int i = 0; i < size2; i++) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                nextGreater[nums2[st.top()]] = nums2[i];
                st.pop();
            }

            st.push(i);
        }

        for (int i = 0; i < size1; i++) {
            if (nextGreater.count(nums1[i]))
                result[i] = nextGreater[nums1[i]];
        }

        return result;
    }
};