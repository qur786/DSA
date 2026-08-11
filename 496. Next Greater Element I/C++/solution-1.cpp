class Solution {
public:
    vector<int> nGE(vector<int>& array) {
        int size = array.size();
        vector<int> result(size, -1);
        stack<int> st;
        for (int i = 0; i < size; i++) {
            while (!st.empty() && array[st.top()] < array[i]) {
                result[st.top()] = array[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<int> nextGreaterArray = nGE(nums2);
        vector<int> result(size1, -1);
        unordered_map<int, int> nums2NGE;
        for (int i = 0; i < size2; i++) {
            nums2NGE[nums2[i]] = nextGreaterArray[i];
        }
        for (int i = 0; i < size1; i++) {
            result[i] = nums2NGE[nums1[i]];
        }

        return result;
    }
};