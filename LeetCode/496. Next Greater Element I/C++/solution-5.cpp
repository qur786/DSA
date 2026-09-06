class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size = nums2.size();
        stack<int> st;
        unordered_map<int, int> nums2Map;

        for (int i = 0; i < size; i++) {
            while (!st.empty() && (nums2[st.top()] < nums2[i])) {
                nums2Map[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        vector<int> answer;
        answer.reserve(nums1.size());

        for (int n : nums1)
            answer.push_back(nums2Map.count(n) ? nums2Map[n] : -1);

        return answer;
    }
};