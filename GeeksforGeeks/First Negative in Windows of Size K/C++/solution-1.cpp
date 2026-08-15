class Solution {
	public:
	vector<int> firstNegInt(vector<int>& arr, int k) {
		// code here
		deque<int> dq;
		int size = arr.size();
		vector<int> result;
		
		result.reserve(size - k + 1);
		
		for (int i = 0; i < size; i++) {
			while (!dq.empty() && (i - dq.front()) >= k)
				dq.pop_front();
			if (arr[i] < 0)
				dq.push_back(i);
			
			if (i >= (k - 1))
				result.push_back(dq.empty() ? 0 :arr[dq.front()]);
		}
		
		return result;
	}
};
