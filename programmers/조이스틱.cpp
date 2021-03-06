#include <string>
#include <vector>

using namespace std;

int solution(string name) {
	int answer = 0;
	int len = name.length();
	int turn = len - 1;
    
	for (int i = 0; i < len; i++) {
		answer += min(name[i] - 'A', 26 - (name[i] - 'A'));
		int n = i + 1;
		while (n < len && name[n] == 'A') n++;
		turn = min(turn, i + len - n + min(i, len - n));
	}
	answer += turn;

	return answer;
}
