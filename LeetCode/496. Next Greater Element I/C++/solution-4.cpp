class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> greaterMap;

        int size = nums2.size();
        stack<int> st;

        for (int i = 0; i < size; i++) {
            while (!st.empty() && (nums2[i] > st.top())) {
                greaterMap[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        int size1 = nums1.size();
        vector<int> answer(nums1.size());

        for (int i = 0; i < size1; i++) {
            answer[i] = greaterMap.count(nums1[i]) ? greaterMap[nums1[i]] : -1;
        }

        return answer;
    }
};