int uniquePaths(int m, int n) {
	int dp[102][102];
	dp[1][1] = 1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) continue;
			if (i == 1) dp[i][j] = dp[i][j - 1];
			else if (j == 1) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[m][n];
}


// overflow..
// int uniquePaths(int m, int n) {
// 	long long up = 1;
// 	for (int i = 0; i < n - 1; i++) {
// 		up *= (m + n - 2 - i);
// 	}
// 
// 	long long down = 1;
// 	for (int i = 0; i < n - 1; i++) {
// 		down *= (n - 1 - i);
// 	}
// 
// 	return up / down;
// }
