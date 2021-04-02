#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	vector<string> dict;

	for (int i = 0; i < 26; i++) {
		string st = "";
		st.push_back('A' + i);
		dict.push_back(st);
	}

	for (int i = 0; i < msg.length();) {
		int j;
		int ans = -1;
		string st;
		for (j = 1; j <= msg.length() - i; j++) {
			int found = 0;
			st = msg.substr(i, j);
			for (int k = 0; k < dict.size(); k++) {
				if (dict[k].compare(st) == 0) {
					ans = k;
					found = 1;
					break;
				}
			}
			if (!found)
				break;
		}

		dict.push_back(st);
		answer.push_back(ans + 1);

		i += (j - 1);
		if (i == msg.length() - 1 && j == 1) break;
	}

	return answer;
}
