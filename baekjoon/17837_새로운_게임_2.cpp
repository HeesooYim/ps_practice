#include <vector>
#include <iostream>
using namespace std;

int N, K;
int arr[14][14];
int dy[5] = { 0,0,0,-1,1 };
int dx[5] = { 0,1,-1,0,0 };
struct mal {
	int r, c, d;
};
vector<mal> vec;
vector<int> chess[14][14] = {};

int dir(int d) {
	if (d == 1) return 2;
	if (d == 2) return 1;
	if (d == 3) return 4;
	return 3;
}

bool check(int nr, int nc) {
	if (nr < 1 || nc < 1 || nr > N || nc > N || arr[nr][nc] == 2)
		return false;
	return true;
}

bool move() {
	for (int i = 0; i < vec.size(); i++) {
		int r = vec[i].r;
		int c = vec[i].c;
		int nr = r + dy[vec[i].d];
		int nc = c + dx[vec[i].d];

		if(!check(nr, nc)){
			vec[i].d = dir(vec[i].d);
			nr = r + dy[vec[i].d];
			nc = c + dx[vec[i].d];
		}
		if (!check(nr, nc)) {
			continue;
		}

		if (arr[nr][nc] == 0) {
			for (int j = 0; j < chess[r][c].size(); j++) {
				if (chess[r][c][j] == i) {
					while (1) {
						int x = chess[r][c][j];
						chess[r][c].erase(chess[r][c].begin() + j);
						chess[nr][nc].push_back(x);
						vec[x].r = nr;
						vec[x].c = nc;
						if (chess[r][c].size() == j) break;
					}
				}
			}
		}
		else {
			for (int j = 0; j < chess[r][c].size(); j++) {
				if (chess[r][c][j] == i) {
					while (1) {
						int x = chess[r][c].back();
						chess[r][c].pop_back();
						chess[nr][nc].push_back(x);
						vec[x].r = nr;
						vec[x].c = nc;
						if (chess[r][c].size() == j) break;
					}
				}
			}
		}

		if (chess[nr][nc].size() >= 4) return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	for (int i = 0; i < K; i++) {
		mal m;
		cin >> m.r >> m.c >> m.d;
		vec.push_back(m);
		chess[m.r][m.c].push_back(i);
	}

	int t = 0;
	while (t <= 1000) {
		t++;
		if (move()) break;
	}

	if (t > 1000) t = -1;
	cout << t;
	
	return 0;
}
