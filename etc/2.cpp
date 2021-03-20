#include <iostream>
using namespace std;
int main() {
	bool arr[52];
	long long dp[52] = {};	// long long 때문에 시간을 많이 버렸다..
	dp[0] = 1;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		arr[i] = c - '0';
	}
	
	if(arr[1]) dp[1] = 1;

	for (int i = 2; i < N; i++) {
		if (arr[i] == 0) continue;
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	
	cout << dp[N - 1];
	
	return 0;
}
