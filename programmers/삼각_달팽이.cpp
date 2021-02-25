#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	vector<vector<int> > vec(n, vector<int>(n, 0));
	int dy[3] = { 1,0,-1 };
	int dx[3] = { 0,1,-1 };

	int num = 1;
	int d = 0;
	int si = -1, sj = 0;
	int sum = n * (n + 1) / 2;

	while (1) {
		int ni, nj;
		ni = si + dy[d];
		nj = sj + dx[d];
		if (ni < 0 || nj < 0 || ni >= n || nj >= n || vec[ni][nj] != 0) {
			d = (d + 1) % 3;
			continue;
		}

		vec[ni][nj] = num;
		num++;
		si = ni;
		sj = nj;

		if (num == sum + 1)
			break;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vec[i][j] == 0) continue;
			answer.push_back(vec[i][j]);
		}
	}

	return answer;
}
