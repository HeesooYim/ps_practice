//dp
class Solution {
public:
	int jump(vector<int>& nums) {
		vector<int> dp(nums.size());

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 1; j <= nums[i]; j++) {
				if (i + j >= nums.size()) break;
				if (dp[i + j] == 0) dp[i + j] = dp[i] + 1;
				else dp[i + j] = min(dp[i + j], dp[i] + 1);
			}
		}

		return dp[nums.size() - 1];
	}
};

//greedy
class Solution {
public:
	int jump(vector<int>& nums) {
		int ret = 0;
		int far = 0;
		int cur = 0;

		for (int i = 0; i < nums.size() - 1; i++) {
			far = max(far, i + nums[i]);
			if (i == cur) {
				ret++;
				cur = far;
			}
		}
		return ret;
	}
};
