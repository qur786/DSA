class Solution {
	public:
	vector<int> maxOfMins(vector<int>& arr) {
		//  code here
		arr.push_back(INT_MIN); // Santient value
		int size = arr.size();
		vector<int> maxOfMinsArr(size - 1, INT_MIN);
		stack<int> monotonicIncreasingSt;
		
		for (int right = 0; right < size; right++) {
			while (!monotonicIncreasingSt.empty() && (arr[right] < arr[monotonicIncreasingSt.top()])) {
				int currentIndex = monotonicIncreasingSt.top(); monotonicIncreasingSt.pop();
				int left = monotonicIncreasingSt.empty() ? -1 : monotonicIncreasingSt.top();
				int windowSize = right - left - 1;
				maxOfMinsArr[windowSize - 1] = max(maxOfMinsArr[windowSize - 1], arr[currentIndex]);
			}
			monotonicIncreasingSt.push(right);
		}
		
		arr.pop_back(); // Removing Santient value
		
		for (int i = size - 2; i > 0; i--) {
			maxOfMinsArr[i - 1] = max(maxOfMinsArr[i - 1], maxOfMinsArr[i]);
		}
		
		return maxOfMinsArr;
	}
};
