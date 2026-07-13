class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersection(nums2, nums1);

        vector<int> result;
        unordered_set<int> numSet1, numSet2;

        for (int n : nums1)
            numSet1.insert(n);
        for (int n : nums2)
            if (numSet1.count(n))
                numSet2.insert(n);

        for (int n : numSet2)
            result.push_back(n);

        return result;
    }
};