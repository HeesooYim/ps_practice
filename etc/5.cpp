#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
char arr[22][1002];
int N, M;

int bfs(int si, int sj) {
	queue <pair<int, int>> q;
	int visit[22][1002] = {};

	q.push({ si,sj });
	visit[si][sj] = 1;
	while (!q.empty()) {
		int fi = q.front().first;
		int fj = q.front().second;
		q.pop();

		if (fi == N - 1) continue;
		if (arr[fi + 1][fj] != 'x') {
			q.push({ fi + 1,fj });
			visit[fi + 1][fj] = visit[fi][fj];
			continue;
		}

		if (fj - 1 >= 0 && arr[fi][fj - 1] != 'x') {
			if (visit[fi][fj - 1] == 0 || visit[fi][fj - 1] > visit[fi][fj] + 1) {
				q.push({ fi,fj - 1 });
				visit[fi][fj - 1] = visit[fi][fj] + 1;
			}
		}
		if (fj + 1 < M && arr[fi][fj + 1] != 'x') {
			if (visit[fi][fj + 1] == 0 || visit[fi][fj + 1] > visit[fi][fj] + 1) {
				q.push({ fi,fj + 1 });
				visit[fi][fj + 1] = visit[fi][fj] + 1;
			}
		}
	}

	int mn = 0x7fffffff;
	for (int i = 0; i < M; i++) {
		if (visit[N - 1][i] == 0) continue;
		mn = min(mn, visit[N - 1][i]);
	}

	return mn;
}

int main() {
	pair<int, int> c[22];
	int cntc = 0;
	cin >> M >> N;
	for(int i=0;i<N;i++)
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'c') {
				c[cntc].first = i;
				c[cntc].second = j;
				cntc++;
			}
		}
	
	int mn = 0x7fffffff;
	for (int i = 0; i < cntc; i++) {
		int ret = bfs(c[i].first, c[i].second);
		mn = min(mn, ret);
	}

	if (mn == 0x7fffffff) mn = -1;
	else mn -= 1;
	cout << mn;

	return 0;
}
// 오답..0-1bfs / 다익스트라로 풀어야 한다..
