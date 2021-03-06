#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;

	int cnt = 0;
	int cnt_z = 0;
	while (1) {
		if (s.compare("1") == 0)
			break;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') {
				s.erase(s.begin() + i);
				i--;
				cnt_z++;
			}
		}

		int len = s.length();
		s.clear();
		while (len > 0) {
			s.insert(s.begin(), (len % 2) + '0');
			len = len / 2;
		}
		cnt++;
	}

	answer.push_back(cnt);
	answer.push_back(cnt_z);
	return answer;
}
