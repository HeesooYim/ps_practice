#include <vector>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		vector<int> row(N, 0);
		vector<int> col(N, 0);

		int input;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> input;
				row[i - 1] += input;
				col[j - 1] += input;
			}
		}

		int r1, c1, r2, c2, v;
		for (int m = 0; m < M; m++) {
			cin >> r1 >> c1 >> r2 >> c2 >> v;

			for (int i = r1; i <= r2; i++)
				row[i - 1] += (c2 - c1 + 1) * v;

			for (int j = c1; j <= c2; j++)
				col[j - 1] += (r2 - r1 + 1) * v;
		}

		for (int i : row)
			cout << i << ' ';
		cout << '\n';
		for (int i : col)
			cout << i << ' ';
		cout << '\n';
	}

	return 0;
}
