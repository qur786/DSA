class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();

        unordered_map<int, int> nge;
        stack<int> st;

        for (int i = 0; i < size2; i++) {
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                nge[nums2[st.top()]] = nums2[i];
                st.pop();
            }

            st.push(i);
        }

        vector<int> result(size1);

        for (int i = 0; i < size1; i++)
            result[i] = nge.count(nums1[i]) ? nge[nums1[i]] : -1;

        return result;
    }
};