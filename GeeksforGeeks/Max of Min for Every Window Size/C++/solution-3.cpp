class Solution {
	public:
	vector<int> maxOfMins(vector<int>& arr) {
		//  code here
		arr.push_back(INT_MIN);
		int size = arr.size();
		vector<int> answer(size - 1, INT_MIN);
		stack<int> st;
		
		for (int i = 0; i < size; i++) {
			while (!st.empty() && (arr[st.top()] > arr[i])) {
				int currentIndex = st.top(); st.pop();
				int left = st.empty() ? -1 : st.top();
				int windowSize = i - left - 1;
				answer[windowSize - 1] = max(answer[windowSize - 1], arr[currentIndex]);
			}
			st.push(i);
		}
		
		arr.pop_back();
		
		for (int i = size - 2; i > 0; i--) {
			answer[i - 1] = max(answer[i - 1], answer[i]);
		}
		
		return answer;
	}
};
