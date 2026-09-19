class Solution {
	public:
	vector<int> firstNegInt(vector<int>& arr, int k) {
		// code here
		int size = arr.size();
		deque<int> dq;
		vector<int> answer;
		answer.reserve(size - k + 1);
		
		for (int i = 0; i < size; i++) {
			while (!dq.empty() && (i - dq.front()) >= k) {
				dq.pop_front();
			}
			if (arr[i] < 0)
				dq.push_back(i);
			
			if (i >= (k - 1))
				{if (dq.empty())
			answer.push_back(0);
			else
				answer.push_back(arr[dq.front()]); }
		}
		
		return answer;
	}
};
