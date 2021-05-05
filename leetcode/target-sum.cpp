// O(2^N)
class Solution {
public:
	int cnt = 0;
	void dfs(vector<int>& nums, int target, int sum, int n) {
		if (n == nums.size()) {
			if (sum == target) {
				cnt++;
			}
			return;
		}

		dfs(nums, target, sum + nums[n], n + 1);
		dfs(nums, target, sum - nums[n], n + 1);
	}

	int findTargetSumWays(vector<int>& nums, int target) {
		dfs(nums, target, 0, 0);
		return cnt;
	}
};

// O(N)
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int ans = 0;
		int dp[20][2001] = {}; // -1000 ~ 1000
		dp[0][nums[0] + 1000]++;
		dp[0][-nums[0] + 1000]++;

		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < 2000; j++) {
				if (dp[i - 1][j]) {
					dp[i][j + nums[i]] += dp[i - 1][j];
					dp[i][j - nums[i]] += dp[i - 1][j];
				}
			}
		}

		return dp[nums.size() - 1][target + 1000];
	}
};
