#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int arr[26] = {};

	for (int i = 0; i < skill.length(); i++) {
		arr[skill[i] - 'A'] = i + 1;
	}

	for (int i = 0; i < skill_trees.size(); i++) {
		bool possible = true;
		int count = 0;

		for (int j = 0; j < skill_trees[i].length(); j++) {
			int n = skill_trees[i][j] - 'A';
			if (arr[n] <= count + 1)
				count = max(count, arr[n]);
			else {
				possible = false;
				break;
			}
		}

		if (possible) answer++;
	}

	return answer;
}
