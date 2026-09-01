class Solution {
	public:
	vector<int> maxOfMins(vector<int>& arr) {
		//  code here
		int size = arr.size();
		arr.push_back(INT_MIN);
		vector<int> answer(size, INT_MIN);
		stack<int> st;
		
		for (int right = 0; right <= size; right++) {
			while (!st.empty() && (arr[right] < arr[st.top()])) {
				int currentIndex = st.top(); st.pop();
				int left = st.empty() ? -1 : st.top();
				int windowSize = right - left - 1;
				answer[windowSize - 1] = max(answer[windowSize - 1], arr[currentIndex]);
			}
			st.push(right);
		}
		
		for (int i = size - 2; i >= 0; i--) {
			answer[i] = max(answer[i + 1], answer[i]);
		}
		
		arr.pop_back();
		
		return answer;
	}
};
