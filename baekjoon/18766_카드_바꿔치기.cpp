#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int T, n;
	int arr[3][10];
	cin >> T;

	for (int t = 0; t < T; t++) {
		int cheater = 0;
		memset(arr, 0, sizeof(arr));
		cin >> n;

		char a;
		int num;
		for (int i = 0; i < n; i++) {
			cin >> a >> num;
			if (a == 'R') arr[0][num]++;
			else if (a == 'B') arr[1][num]++;
			else arr[2][num]++;
		}

		for (int i = 0; i < n; i++) {
			cin >> a >> num;
			if (a == 'R') arr[0][num]--;
			else if (a == 'B') arr[1][num]--;
			else arr[2][num]--;
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 10; j++) {
				if (arr[i][j]) {
					cheater = 1;
					break;
				}
			}
		}

		if (cheater) cout << "CHEATER\n";
		else cout << "NOT CHEATER\n";
	}
	
	return 0;
}
