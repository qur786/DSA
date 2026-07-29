class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        if (list1.size() > list2.size())
            return findRestaurant(list2, list1);
        unordered_map<string, int> list1Map;
        int size1 = list1.size(), size2 = list2.size();
        vector<string> result;
        int minSum = INT_MAX;

        for (int i = 0; i < size1; i++)
            list1Map[list1[i]] = i;

        for (int i = 0; i < size2; i++) {
            if (i > minSum)
                break;
            if (list1Map.count(list2[i])) {
                int s = i + list1Map[list2[i]];
                if (minSum == s)
                    result.push_back(list2[i]);
                else if (minSum > s) {
                    result.clear();
                    minSum = s;
                    result.push_back(list2[i]);
                }
            }
        }

        return result;
    }
};