#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int r, c, k;
int cntr, cntc;
int arr[101][101] = {};

struct st {
	int val;
	int cnt;
};

bool operator<(st s1, st s2) {
	if (s1.cnt != s2.cnt)
		return s1.cnt < s2.cnt;
	else return s1.val < s2.val;
}

void calc_r() {
	int mx = 0;
	
	for (int i = 1; i <= cntr; i++) {
		int arr_cnt[101] = {};
		vector<st> vec;

		for (int j = 1; j <= cntc; j++) {
			arr_cnt[arr[i][j]]++;
			arr[i][j] = 0;
		}

		for (int j = 1; j < 101; j++) {
			if (arr_cnt[j])
				vec.push_back({ j,arr_cnt[j] });
		}

		sort(vec.begin(), vec.end());

		for (int j = 0; j < vec.size(); j++) {
			arr[i][j * 2 + 1] = vec[j].val;
			arr[i][j * 2 + 2] = vec[j].cnt;
		}

		mx = max(mx, int(vec.size()) * 2);
	}
	cntc = mx;
}

void calc_c() {
	int mx = 0;

	for (int j = 1; j <= cntc; j++) {
		int arr_cnt[101] = {};
		vector<st> vec;

		for (int i = 1; i <= cntr; i++) {
			arr_cnt[arr[i][j]]++;
			arr[i][j] = 0;
		}

		for (int i = 1; i < 101; i++) {
			if (arr_cnt[i])
				vec.push_back({ i,arr_cnt[i] });
		}

		sort(vec.begin(), vec.end());

		for (int i = 0; i < vec.size(); i++) {
			arr[i * 2 + 1][j] = vec[i].val;
			arr[i * 2 + 2][j] = vec[i].cnt;
		}

		mx = max(mx, int(vec.size()) * 2);
	}
	cntr = mx;
}

int main() {
	cin >> r >> c >> k;
	cntr = 3;
	cntc = 3;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	}

	int t = 0;
	while (t <= 100) {
		if (arr[r][c] == k) break;
		if (cntr >= cntc) calc_r();
		else calc_c();

		t++;
	}

	if (t == 101) cout << -1;
	else cout << t;

	return 0;
}
