class Solution {
	private:
	int count = 0;
	void mergeSort(vector<int> & arr, int left, int right) {
		if (left >= right)
			return;
		
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		
		int j = mid + 1;
		for (int i = left; i <= mid; i++) {
			while (j <= right && arr[i] > arr[j]) {
				j++;
			}
			count += (j - (mid + 1));
		}
		
		merge(arr, left, mid, right);
	}
	void merge(vector<int> & arr, int left, int mid, int right) {
		int size1 = mid - left + 1, size2 = right - mid;
		vector<int> arr1(arr.begin() + left, arr.begin() + mid + 1), arr2(arr.begin() + mid + 1, arr.begin() + right + 1);
		
		int i = 0, j = 0, k = left;
		while (i < size1 && j < size2) {
			if (arr1[i] <= arr2[j]) {
				arr[k] = arr1[i]; i++;
			} else {
				arr[k] = arr2[j]; j++;
			}
			k++;
		}
		while (i < size1) {
			arr[k] = arr1[i]; i++;
			k++;
		}
		while (i < size1 && j < size2) {
			arr[k] = arr2[j]; j++;
			k++;
		}
	}
	public:
	int inversionCount(vector<int> &arr) {
		mergeSort(arr, 0, arr.size() - 1);
		return count;
	}
};
