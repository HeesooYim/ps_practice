#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int R, C, M;
int arr[102][102] = {};
struct sh {
	int r, c, s, d, z;
};
vector<sh> vec;
int ans = 0;
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,1,-1 };

void fishing(int t) {
	for (int i = 1; i <= R; i++) {
		if (arr[i][t]) {
			int x = arr[i][t];
			ans += vec[x - 1].z;
			vec.erase(vec.begin() + (x - 1));
			arr[i][t] = 0;
            
			for (int j = x - 1; j < vec.size(); j++) {
				arr[vec[j].r][vec[j].c]--;
			}

			break;
		}
	}
}

void move() {
	int arr1[102][102] = {};
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].s; j++) {
			int nr = vec[i].r + dy[vec[i].d];
			int nc = vec[i].c + dx[vec[i].d];
			if (nr < 1 || nc < 1 || nr > R || nc > C) {
				if (vec[i].d == 1) vec[i].d = 2;
				else if (vec[i].d == 2) vec[i].d = 1;
				else if (vec[i].d == 3) vec[i].d = 4;
				else vec[i].d = 3;
				j--;
				continue;
			}
			vec[i].r = nr;
			vec[i].c = nc;
		}

		int x = arr1[vec[i].r][vec[i].c];
		if (x) {
			if (vec[x - 1].z < vec[i].z) {
				vec[x - 1].s = vec[i].s;
				vec[x - 1].d = vec[i].d;
				vec[x - 1].z = vec[i].z;
			}
			vec.erase(vec.begin() + i);
			i--;
		}
		else {
			arr1[vec[i].r][vec[i].c] = i + 1;
		}
	}
	memcpy(arr, arr1, sizeof(arr));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		struct sh sh1;
		cin >> sh1.r >> sh1.c >> sh1.s >> sh1.d >> sh1.z;
		if (sh1.s != 0) {
			if (sh1.d == 1 || sh1.d == 2) {
				sh1.s = sh1.s % ((R - 1) * 2);
			}
			else {
				sh1.s = sh1.s % ((C - 1) * 2);
			}
		}
		vec.push_back(sh1);
		arr[sh1.r][sh1.c] = i + 1;
	}

	int t = 1;
	while (t<=C) {
		fishing(t);
		move();
		t++;
	}
	
	cout << ans;

	return 0;
}
