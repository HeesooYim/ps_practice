#include <string>
#include <stack>

using namespace std;

bool is_right(string u) {
	stack<char> s;

	for (int i = 0; i < u.length(); i++) {
		char c = u[i];
		if (!s.empty()) {
			char t = s.top();
			if (t == '(' && c == ')')
				s.pop();
			else s.push(c);
		}
		else s.push(c);
	}

	if (s.empty()) return true;
	return false;
}

string solution(string p) {
	string answer = "";
	if (p == "") return "";

	int cnt1 = 0, cnt2 = 0;
	string u = "";
	string v = "";
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') cnt1++;
		if (p[i] == ')') cnt2++;
		if (cnt1 == cnt2) {
			u.append(p.begin(), p.begin() + i + 1);
			v.append(p.begin() + i + 1, p.end());
			break;
		}
	}

	if (is_right(u)) {
		answer += u;
		answer += solution(v);
	}
	else {
		answer += '(';
		answer += solution(v);
		answer += ')';
		for (int i = 1; i < u.length() - 1; i++) {
			if (u[i] == '(') answer += ')';
			else answer += '(';
		}
	}

	return answer;
}
