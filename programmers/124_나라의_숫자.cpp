#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
    
	if (n == 0) return answer;

	int nam = n % 3;
	int mok = n / 3;
	if (nam == 0)
		answer = solution(mok - 1) + "4";
	else if (nam == 2)
		answer = solution(mok) + "2";
	else
		answer = solution(mok) + "1";

	return answer;
}
