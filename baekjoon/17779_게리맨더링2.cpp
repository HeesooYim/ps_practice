#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int A[22][22] = {};
bool B[22][22] = {};
int N;

void border(int x, int y, int d1, int d2) {
	int dx[4] = { 1,1,-1,-1 };
	int dy[4] = { -1,1,1,-1 };

	memset(B, 0, sizeof(B));
	int i = x, j = y;
	int d;
	for (int k = 0; k < 4; k++) {
		if (k % 2 == 0) d = d1;
		else d = d2;
		while (d--) {
			i += dx[k];
			j += dy[k];
			B[i][j] = true;
		}
	}

	bool set = false;
	for (int i = x + 1; i < x + d1 + d2; i++) {
		for (int j = 1; j <= N; j++) {
			if (B[i][j]) {
				set = !set;
				continue;
			}
			B[i][j] = set;
		}
	}
}

int calculate(int x, int y, int d1, int d2) {
	border(x, y, d1, d2);
	
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (B[i][j]) {
				sum5 += A[i][j];
				continue;
			}
			if (1 <= i && i < x + d1 && 1 <= j && j <= y) sum1 += A[i][j];
			else if (1 <= i && i <= x + d2 && y < j && j <= N) sum2 += A[i][j];
			else if (x + d1 <= i && i <= N && 1 <= j && j < y - d1 + d2) sum3 += A[i][j];
			else sum4 += A[i][j];
		}
	}

	int mx = max(sum1, (max(sum2, max(sum3, max(sum4, sum5)))));
	int mn = min(sum1, (min(sum2, min(sum3, min(sum4, sum5)))));
	return mx - mn;
}

int solve() {
	int ans = 987654321;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N - 1; d1++) {
				if (y - d1 < 1) continue;
				for (int d2 = 1; d2 <= N - 1; d2++) {
					if (y + d2 > N) continue;
					if (x + d1 + d2 > N) continue;
					ans = min(ans, calculate(x, y, d1, d2));
				}
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	cout << solve();
}
