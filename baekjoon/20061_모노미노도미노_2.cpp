#include <iostream>
using namespace std;

int arr[10][10] = {};
int score = 0;

void move(int t, int x, int y) {
	if (t == 1) {
		int gx = 4;
		while (gx < 9) {
			if (arr[gx + 1][y]) break;
			gx++;
		}
		arr[gx][y] = 1;

		int by = 4;
		while (by < 9) {
			if (arr[x][by + 1]) break;
			by++;
		}
		arr[x][by] = 1;
	}
	else if (t == 2) {
		int gx = 4;
		while (gx < 9) {
			if (arr[gx + 1][y] || arr[gx + 1][y + 1]) break;
			gx++;
		}
		arr[gx][y] = 1;
		arr[gx][y + 1] = 1;

		int by = 4;
		while (by < 8) {
			if (arr[x][by + 2]) break;
			by++;
		}
		arr[x][by] = 1;
		arr[x][by + 1] = 1;
	}
	else {
		int gx = 4;
		while (gx < 8) {
			if (arr[gx + 2][y]) break;
			gx++;
		}
		arr[gx][y] = 1;
		arr[gx + 1][y] = 1;

		int by = 4;
		while (by < 9) {
			if (arr[x][by + 1] || arr[x + 1][by + 1]) break;
			by++;
		}
		arr[x][by] = 1;
		arr[x + 1][by] = 1;
	}
}

void bomb() {
	for (int i = 6; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			if (!arr[i][j]) break;
			if (arr[i][j] && j == 3) {
				score++;
				for (int k = i - 1; k >= 3; k--) {
					for (int l = 0; l < 4; l++) {
						arr[k + 1][l] = arr[k][l];
					}
				}
			}
		}
	}

	for (int j = 6; j < 10; j++) {
		for (int i = 0; i < 4; i++) {
			if (!arr[i][j]) break;
			if (arr[i][j] && i == 3) {
				score++;
				for (int k = j - 1; k >= 3; k--) {
					for (int l = 0; l < 4; l++) {
						arr[l][k + 1] = arr[l][k];
					}
				}
			}
		}
	}
}

void light() {
	int cnt = 0;
	for (int i = 4; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j]) {
				cnt++;
				break;
			}
		}
	}

	if (cnt) {
		for (int i = 9 - cnt; i >= 6 - cnt; i--) {
			for (int j = 0; j < 4; j++) {
				arr[i + cnt][j] = arr[i][j];
			}
		}
		for (int i = 4; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j] = 0;
			}
		}
	}

	cnt = 0;
	for (int j = 4; j < 6; j++) {
		for (int i = 0; i < 4; i++) {
			if (arr[i][j]) {
				cnt++;
				break;
			}
		}
	}

	if (cnt) {
		for (int j = 9 - cnt; j >= 6 - cnt; j--) {
			for (int i = 0; i < 4; i++) {
				arr[i][j + cnt] = arr[i][j];
			}
		}
		for (int j = 4; j < 6; j++) {
			for (int i = 0; i < 4; i++) {
				arr[i][j] = 0;
			}
		}
	}
}

int count() {
	int ret = 0;
	for (int i = 6; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j]) ret++;
		}
	}
	for (int j = 6; j < 10; j++) {
		for (int i = 0; i < 4; i++) {
			if (arr[i][j]) ret++;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t, y, x;
		cin >> t >> x >> y;

		move(t, x, y);
		bomb();
		light();
	}
	cout << score << ' ' << count();

	return 0;
}
