class Solution {
  public:
    bool checkSubset(vector<int> & arr, int k, int ans) {
        int count = 1;
        int subsetSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > ans) return false;
            if (subsetSum + arr[i] > ans) {
                subsetSum = arr[i];
                count += 1;
            } else {
                subsetSum += arr[i];
            }
        }
        
        return count <= k;
    }
    int splitArray(vector<int>& arr, int k) {
        int minVal = *max_element(arr.begin(), arr.end());
        int maxVal = accumulate(arr.begin(), arr.end(), 0);
        int result = 0;
        int low = minVal, high = maxVal;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (checkSubset(arr, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};