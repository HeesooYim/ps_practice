#include <iostream>
using namespace std;
int main() {
	int arr[52][52];
	int size[52] = {};
	size[1] = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			arr[i][j] = c - '0';
			if (arr[i][j]) size[1]++;
		}

	size[0] = size[1];

	for (int s = 2; s <= N; s++) {
		for (int i = 0; i <= N - s; i++) {
			for (int j = 0; j <= N - s; j++) {
				bool able = 1;

				for (int k = i; k < i + s; k++) {
					for (int l = j; l < j + s; l++) {
						if (!arr[k][l]) {
							able = 0;
							break;
						}
					}
					if (!able) break;
				}
				if (able) size[s]++;
			}
		}

		if (size[s] == 0) break;
		size[0] += size[s];
	}

	cout << "total: " << size[0] << '\n';
	for (int i = 1; i <= N; i++) {
		if (size[i] == 0) continue;
		cout << "size[" << i << "]: " << size[i] << '\n';
	}
	
	return 0;
}
