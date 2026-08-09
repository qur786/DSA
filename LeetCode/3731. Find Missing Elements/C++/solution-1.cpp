class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto [minIt, maxIt] = minmax_element(nums.begin(), nums.end());
        int minElement = *minIt, maxElement = *maxIt;
        vector<int> missingValues;
        array<int, 101> values{};
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            values[nums[i]]++;
        }
        for (int i = minElement; i < maxElement; i++) {
            if (!values[i])
                missingValues.push_back(i);
        }

        return missingValues;
    }
};