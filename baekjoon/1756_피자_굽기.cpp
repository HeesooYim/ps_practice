#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> oven;

int binarySearch(int n, int D) {
	int s = 0, e = D;
	int mid;
	int ret = -1;

	while (s <= e) {
		mid = (s + e) / 2;

		if (oven[mid] >= n) {
			ret = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int D, N, a;

	cin >> D >> N;
	int mn = 1000000000;
	for (int i = 0; i < D; i++) {
		cin >> a;
		if (mn > a) {
			mn = a;
		}
		oven.push_back(mn);
	}

	int ret;
	int depth = D - 1;
	for (int i = 0; i < N; i++) {
		cin >> a;

		ret = binarySearch(a, depth);
		depth = ret - 1;
	}

	cout << ret + 1;

	return 0;
}
