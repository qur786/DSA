class Solution {
	private:
	void mergeSort(vector<int> & arr, int left, int right, int & count) {
		if (left >= right)
			return;
		
		int mid = left + (right - left) / 2;
		
		mergeSort(arr, left, mid, count);
		mergeSort(arr, mid + 1, right, count);
		int j = mid + 1;
		
		for (int i = left; i <= mid; i++) {
			while (j <= right && arr[i] > arr[j])
				j++;
			
			count += (j - (mid + 1));
		}
		merge(arr, left, mid, right);
	}
	void merge(vector<int> & arr, int left, int mid, int right) {
		vector<int> nums1(arr.begin() + left, arr.begin() + mid + 1);
		vector<int> nums2(arr.begin() + mid + 1, arr.begin() + right + 1);
		
		int i = 0, j = 0, k = left;
		int size1 = nums1.size(), size2 = nums2.size();
		
		while (i < size1 && j < size2) {
			if (nums1[i] <= nums2[j]) {
				arr[k] = nums1[i]; i++;
			} else {
				arr[k] = nums2[j]; j++;
			}
			k++;
		}
		while (i < size1) {
			arr[k] = nums1[i]; i++;
			k++;
		}
		while (j < size2) {
			arr[k] = nums2[j]; j++;
			k++;
		}
	}
	public:
	int inversionCount(vector<int> &arr) {
		int count = 0;
		mergeSort(arr, 0, arr.size() - 1, count);
		return count;
	}
};
