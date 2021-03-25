#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int t, int m, int p) {
	string answer = "";
	int num = 0;
	int i = 1;

	if (p == m) p = 0;
	while (i <= t * m) {
		int numcp = num;
		stack<char> st;

		if (numcp == 0) st.push('0');
		while (numcp > 0) {
			int c = numcp % n;
			numcp = numcp / n;
			char ch;

			if (c > 9) ch = (c - 10) + 'A';
			else ch = c + '0';
			st.push(ch);
		}

		while (!st.empty()) {
			if (i%m == p)
				answer.push_back(st.top());
			st.pop();
			i++;
			if (i > t*m) break;
		}

		num++;
	}

	return answer;
}
