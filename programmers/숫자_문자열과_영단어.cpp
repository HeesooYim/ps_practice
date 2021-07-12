#include <string>
#include <vector>

using namespace std;

string num[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight","nine" };

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			answer = answer * 10 + (s[i] - '0');
			continue;
		}
		for (int j = 0; j < 10; j++) {
			if (!s.compare(i, num[j].length(), num[j])) {
				answer = answer * 10 + j;
				i += num[j].length() - 1;
				break;
			}
		}
	}
    
	return answer;
}
