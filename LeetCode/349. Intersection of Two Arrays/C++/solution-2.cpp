class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        if (size1 < size2)
            return intersection(nums2, nums1);
        vector<int> inter;
        unordered_set<int> numSet1, numSet2;

        for (int n : nums1)
            numSet1.insert(n);
        for (int n : nums2)
            numSet2.insert(n);

        for (int n : numSet1)
            if (numSet2.count(n))
                inter.push_back(n);

        return inter;
    }
};