class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        if (list2.size() < list1.size())
            return findRestaurant(list2, list1);
        unordered_map<string, int> list1Map;
        vector<string> result;
        int minSum = INT_MAX;

        int curr = 0;
        for (const string& str : list1)
            list1Map[str] = curr++;

        int size = list2.size();
        for (int i = 0; i < size; i++) {
            if (!list1Map.count(list2[i]))
                continue;
            if (i > minSum)
                break;

            int sum = i + list1Map[list2[i]];

            if (minSum > sum) {
                minSum = sum;
                result.clear();
                result.push_back(list2[i]);
            } else if (minSum == sum) {
                result.push_back(list2[i]);
            }
        }

        return result;
    }
};