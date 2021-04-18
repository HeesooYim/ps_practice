#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());

	int s = 0;
	int i = people.size() - 1;
	while (s <= i) {
		for (; i > s; i--) {
			if (people[s] + people[i] <= limit) {
				i--;
				break;
			}
			else {
				answer++;
			}
		}
		answer++;
		s++;
	}

	return answer;
}

// 이렇게 풀었다가 시간초과가 나서 위처럼 수정했다..
// int solution(vector<int> people, int limit) {
// 	int answer = 0;
// 	sort(people.begin(), people.end());
// 
// 	while (!people.empty()) {
// 		for (int i = people.size() - 1; i > 0; i--) {
// 			if (people[0] + people[i] <= limit) {
// 				people.erase(people.begin() + i);
// 				break;
// 			}
//             else {
// 				people.erase(people.begin() + i);
// 				answer++;
// 			}
// 		}
// 		people.erase(people.begin());
// 		answer++;
// 	}
// 
// 	return answer;
// }
