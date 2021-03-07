#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int N, M;
int arr[52][52];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<pair<int, int>> vec;
bool visit_vec[12];
int cnt0 = 0;
int ans = 0x7fffffff;

void spread() {
	queue<pair<int, int>> q;
	int visit[52][52] = {};
	int time = 0;
	int cnt = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (visit_vec[i]) {
			q.push(vec[i]);
			visit[vec[i].first][vec[i].second] = 1;
		}
	}

	while (!q.empty()) {
		int fi = q.front().first;
		int fj = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ni = fi + dy[i];
			int nj = fj + dx[i];

			if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
			if (visit[ni][nj]) continue;

			if (arr[ni][nj] != 1) {
				q.push({ ni,nj });
				visit[ni][nj] = visit[fi][fj] + 1;

				if (arr[ni][nj] == 0) cnt++;
				time = max(time, visit[ni][nj] - 1);
				if (cnt == cnt0) {
					ans = min(ans, time);
					return;
				}
			}
		}
	}
}

void select(int n, int m) {
	if (n > vec.size()) return;
	if (m == M) {
		spread();
		return;
	}

	visit_vec[n] = 1;
	select(n + 1, m + 1);
	visit_vec[n] = 0;
	select(n + 1, m);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) vec.push_back({ i,j });
			if (arr[i][j] == 0) cnt0++;
		}
	}

	if (cnt0 == 0) ans = 0;
	else select(0, 0);

	if (ans == 0x7fffffff) ans = -1;
	cout << ans;

	return 0;
}
