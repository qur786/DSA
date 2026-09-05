class Solution {
	public:
	vector<int> firstNegInt(vector<int>& arr, int k) {
		// code here
		int size = arr.size();
		vector<int> answer;
		answer.reserve(size - k + 1);
		deque<int> dq;
		
		for (int i = 0; i < size; i++) {
			while (!dq.empty() && (i - dq.front()) >= k)
				dq.pop_front();
			
			if (arr[i] < 0)
				dq.push_back(i);
			
			if (i >= (k - 1))
				answer.push_back(dq.empty() ? 0 : arr[dq.front()]);
		}
		
		return answer;
	}
};
