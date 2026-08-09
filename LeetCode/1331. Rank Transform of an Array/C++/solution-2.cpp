class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int size = arr.size();
        vector<int> temp(arr.begin(), arr.end());
        vector<int> result(size);
        sort(temp.begin(), temp.end());

        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        for (int i = 0; i < size; i++) {
            result[i] =
                distance(temp.begin(),
                         lower_bound(temp.begin(), temp.end(), arr[i])) +
                1;
        }

        return result;
    }
};