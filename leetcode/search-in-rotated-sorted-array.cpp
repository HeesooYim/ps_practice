class Solution {
public:
	int binarySearch(int left, int right, vector<int>& nums, int target) {
		int mid;

		while (left <= right) {
			mid = (left + right) / 2;
			// mid = left + (right - left) / 2;	avoid overflow
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
				right = mid - 1;
			else left = mid + 1;
		}

		return -1;
	}

	int search(vector<int>& nums, int target) {
		int i = 0;
		for (; i < nums.size() - 1; i++) {
			if (nums[i] > nums[i + 1])
				break;
		}

		if (nums[0] <= target && target <= nums[i])
			return binarySearch(0, i, nums, target);
		else
			return binarySearch(i + 1, nums.size() - 1, nums, target);
	}
};
