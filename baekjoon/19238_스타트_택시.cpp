#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int N, M, fuel;
int arr[22][22];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
int ti, tj;
vector<pair<int, int>> s;
vector<pair<int, int>> e;

pair<int,int> bfs_s() {
	int mn = 0x7fffffff;
	int mi = -1;
	for (int i = 0; i < s.size(); i++) {
		if (ti == s[i].first && tj == s[i].second) {
			return { i,0 };
		}
	}

	int visit[22][22] = {};
	queue<pair<int, int>> q;
	q.push({ ti,tj });
	visit[ti][tj] = 1;

	while (!q.empty()) {
		int fi = q.front().first;
		int fj = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ni = fi + dy[i];
			int nj = fj + dx[i];

			if (ni<1 || nj<1 || ni>N || nj>N || arr[ni][nj] || visit[ni][nj]) continue;

			q.push({ ni,nj });
			visit[ni][nj] = visit[fi][fj] + 1;

			for (int j = 0; j < s.size(); j++) {
				if (ni == s[j].first && nj == s[j].second) {
					if (mn == visit[ni][nj] - 1) {
						if (s[mi].first == s[j].first) {
							if (s[mi].second > s[j].second) {
								mi = j;
							}
						}
						else if (s[mi].first > s[j].first) {
							mi = j;
						}
					}
					else if (mn > visit[ni][nj] - 1) {
						mn = visit[ni][nj] - 1;
						mi = j;
					}
				}
			}
		}
	}

	return { mi,mn };
}

int bfs_e(int ei, int ej) {
	int visit[22][22] = {};
	queue<pair<int, int>> q;
	q.push({ ti,tj });
	visit[ti][tj] = 1;

	while (!q.empty()) {
		int fi = q.front().first;
		int fj = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ni = fi + dy[i];
			int nj = fj + dx[i];

			if (ni<1 || nj<1 || ni>N || nj>N || arr[ni][nj] || visit[ni][nj]) continue;

			q.push({ ni,nj });
			visit[ni][nj] = visit[fi][fj] + 1;

			if (ni == ei && nj == ej) {
				return visit[ni][nj] - 1;
			}
		}
	}

	return -1;
}

int solve() {
	for (int i = 0; i < M; i++) {
		pair<int, int> p = bfs_s();
		int pi = p.first;
		int pf = p.second;
		if (pi == -1) return -1;

		fuel -= pf;
		if (fuel < 0) return -1;

		ti = s[pi].first;
		tj = s[pi].second;

		int ret = bfs_e(e[pi].first, e[pi].second);
		if (ret == -1) return -1;

		fuel -= ret;
		if (fuel < 0) return -1;

		fuel += ret * 2;

		ti = e[pi].first;
		tj = e[pi].second;

		s.erase(s.begin() + pi);
		e.erase(e.begin() + pi);
	}

	return fuel;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> fuel;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> ti >> tj;

	int s1, s2, e1, e2;
	for (int i = 0; i < M; i++) {
		cin >> s1 >> s2 >> e1 >> e2;
		s.push_back({ s1,s2 });
		e.push_back({ e1,e2 });
	}

	cout << solve();

	return 0;
}
