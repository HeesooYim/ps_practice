#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> vec;

bool binarySearch(int n) {
	int s = 0, e = vec.size() - 1;
	int mid;

	while (s <= e) {
		mid = (s + e) / 2;
		if (n < vec[mid]) {
			e = mid - 1;
		}
		else if (vec[mid] < n) {
			s = mid + 1;
		}
		else return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, a;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a;
		cout << binarySearch(a) << ' ';
	}
	
	return 0;
}
