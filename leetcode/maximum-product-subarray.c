#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define min(a,b)  (((a) < (b)) ? (a) : (b))

int maxProduct(int* nums, int numsSize) {
	int dp[20002][2];
	int ans = nums[0];
	dp[0][0] = nums[0];
	dp[0][1] = nums[0];

	for (int i = 1; i < numsSize; i++) {
		dp[i][0] = max(nums[i], max(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]));
		dp[i][1] = min(nums[i], min(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]));
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}

	return ans;
}

