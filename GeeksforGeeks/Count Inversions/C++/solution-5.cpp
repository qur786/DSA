class Solution {
	private:
	int count = 0;
	void mergeSort(vector<int> & arr, int low, int high) {
		if (low >= high)
			return;
		
		int mid = low + (high - low) / 2;
		
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		int j = mid + 1;
		
		for (int i = low; i <= mid; i++) {
			while (j <= high && arr[i] > arr[j])
				j++;
			
			count += j - (mid + 1);
		}
		merge(arr, low, mid, high);
	}
	void merge(vector<int> & arr, int low, int mid, int high) {
		vector<int> nums1(arr.begin() + low, arr.begin() + mid + 1);
		vector<int> nums2(arr.begin() + mid + 1, arr.begin() + high + 1);
		int size1 = nums1.size(), size2 = nums2.size();
		
		int i = 0, j = 0, k = low;
		
		while (i < size1 && j < size2) {
			if (nums1[i] <= nums2[j]) {
				arr[k] = nums1[i];
				i++;
			} else {
				arr[k] = nums2[j];
				j++;
			}
			k++;
		}
		while (i < size1) {
			arr[k] = nums1[i];
			i++;
			k++;
		}
		while (i < size1 && j < size2) {
			arr[k] = nums2[j];
			j++;
			k++;
		}
	}
	public:
	int inversionCount(vector<int> &arr) {
		// code here
		mergeSort(arr, 0, arr.size() - 1);
		
		return count;
	}
};
