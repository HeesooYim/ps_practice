#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

// 2차원 배열 -> 메모리 초과
vector<pair<int, int>> vec[100002];
bool visit[100002];
int n1, n2;

bool bfs(int mid) {
	queue<int> q;
	q.push(n1);
	visit[n1] = 1;

	while (!q.empty()) {
		int f = q.front();
		q.pop();

		if (f == n2) {
			return true;
		}

		for (int i = 0; i < vec[f].size(); i++) {
			int n = vec[f][i].first;

			// 중량 최대 mid일 때 cost 값 확인
			if (visit[n] || vec[f][i].second < mid) continue;
			q.push(n);
			visit[n] = 1;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int c, mx = 0;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2 >> c;
		vec[n1].push_back({ n2,c });
		vec[n2].push_back({ n1,c });
		mx = max(mx, c);
	}
	cin >> n1 >> n2;

	int s = 0, e = mx;
	int mid;
	while (s <= e) {
		memset(visit, 0, sizeof(visit));
		mid = (s + e) / 2;
		if (bfs(mid)) {		// 중량 최댓값에 따라 탐색 가능한지 확인
			s = mid + 1;	// 탐색 가능시 중량을 늘림
		}
		else {
			e = mid - 1;	// 탐색 불가시 중량 줄임
		}
	}
	cout << e;

	return 0;
}
