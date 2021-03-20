#include <iostream>
#include <string>
using namespace std;
int main() {
	int N;
	int time[2000] = {};

	cin >> N;
	for (int t = 0; t < N; t++) {
		int sh, sm, eh, em;
		char c;
		cin >> sh >> c >> sm >> c >> eh >> c >> em;

		for (int i = sh * 60 + sm; i <= eh * 60 + em; i++)
			time[i]++;
	}

	int s = -1;
	int e = -1;
	for (int i = 0; i < 2000;i++) {
		if (time[i] == N) {
			s = i;
			for (int j = i + 1; j < 2000; j++) {
				if (time[j] != N) {
					e = j - 1;
					break;
				}
			}
			break;
		}
	}
	
	if (s == -1) cout << -1;
	else {
		string sh = "", sm = "";
		string eh = "", em = "";

		if (s / 60 < 10) {
			sh += '0';
			sh += (s / 60) + '0';
			cout << sh << ':';
		}
		else cout << s / 60 << ':';

		if (s % 60 < 10) {
			sm += '0';
			sm += (s % 60) + '0';
			cout << sm << " ~ ";
		}
		else cout << s % 60 << " ~ ";

		if (e / 60 < 10) {
			eh += '0';
			eh += (e / 60) + '0';
			cout << eh << ':';
		}
		else cout << e / 60 << ':';


		if (e % 60 < 10) {
			em += '0';
			em += (e % 60) + '0';
			cout << em;
		}
		else cout << e % 60;
	}

	return 0;
}
