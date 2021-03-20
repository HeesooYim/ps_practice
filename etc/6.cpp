#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int dy[2] = { 1,0 };
	int dx[2] = { 0,1 };
	int N, M;
	cin >> M >> N;
	vector<vector<int>>arr(N, vector<int>(M, 0));
	vector<vector<int>>dp(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = arr[i][j];
				continue;
			}

			dp[i][j] = arr[i][j] + max(i - 1 < 0 ? 0 : dp[i - 1][j], j - 1 < 0 ? 0 : dp[i][j - 1]);
		}
	}

	cout << dp[N - 1][M - 1];

	return 0;
}
