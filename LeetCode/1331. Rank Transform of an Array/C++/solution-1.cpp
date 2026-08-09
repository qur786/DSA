class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int size = arr.size();
        vector<int> temp(arr.begin(), arr.end());
        vector<int> result(size);
        sort(temp.begin(), temp.end());
        unordered_map<int, int> rankMap;

        int rank = 1;
        for (int i = 0; i < size; i++) {
            if (!rankMap.count(temp[i]))
                rankMap[temp[i]] = rank++;
        }

        for (int i = 0; i < size; i++) {
            result[i] = rankMap[arr[i]];
        }

        return result;
    }
};