
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/* (from hackerrank)
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */

void dfs(int* nums, int n, int numsSize, int* temp, int ts, int** ret, int* rs, int** returnColumnSizes) {
	if (n == numsSize) {
		for (int i = 0; i < ts; i++) ret[*rs][i] = temp[i];
		(*returnColumnSizes)[(*rs)++] = ts;
		return;
	}
	dfs(nums, n + 1, numsSize, temp, ts, ret, rs, returnColumnSizes);
	temp[ts] = nums[n];
	dfs(nums, n + 1, numsSize, temp, ts + 1, ret, rs, returnColumnSizes);
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = pow(2, numsSize);
	*returnColumnSizes = malloc((*returnSize) * sizeof(int*));
	int** ret = malloc((*returnSize) * sizeof(int*));
	int* temp = malloc(sizeof(int) * numsSize);
	int r_size = 0;

	for (int i = 0; i < *returnSize; i++) {
		(*returnColumnSizes)[i] = numsSize;
		ret[i] = (int*)malloc((*returnColumnSizes)[i] * sizeof(int));
	}

	dfs(nums, 0, numsSize, temp, 0, ret, &r_size, returnColumnSizes);

	return ret;
}

// in c++
// class Solution {
// public:
//     void dfs(int n, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ret){
//         if(n==nums.size()){
//             ret.push_back(temp);
//             return;
//         }
// 
// 
//         dfs(n+1, temp, nums, ret);
//         temp.push_back(nums[n]);
//         dfs(n+1, temp, nums, ret);
//     }
// 
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ret;
//         vector<int> temp;
//         dfs(0, temp, nums, ret);
// 
//         return ret;
//     }
// };
