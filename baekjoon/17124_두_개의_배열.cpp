#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int search(int mid, vector<int>& B, int find) {
	if (find < B[mid]) {
		if (mid - 1 >= 0 && B[mid] - find >= find - B[mid - 1])
			return mid - 1;
		else return mid;
	}
	else {
		if (mid + 1 < B.size() && find - B[mid] > B[mid + 1] - find)
			return mid + 1;
		else return mid;
	}
}

int binarySearch(int left, int right, vector<int>& B, int find) {
	int mid;

	while (left <= right) {
		mid = left + (right - left) / 2;
		if (find < B[mid])
			right = mid - 1;
		else if (B[mid] < find)
			left = mid + 1;
		else return mid;
	}

	return search(mid, B, find);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	int n, m;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> m;
		vector<int> A(n, 0);
		vector<int> B(m, 0);
		long long sum = 0;

		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 0; i < m; i++)
			cin >> B[i];

		sort(B.begin(), B.end());

		for (int a : A) {
			int c = binarySearch(0, m - 1, B, a);
			sum += B[c];
		}

		cout << sum << '\n';
	}

	return 0;
}
