#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long calc(long long num1, long long num2, long long op) {
	if (op == '+')
		return num1 + num2;
	else if (op == '-')
		return num1 - num2;
	else return num1 * num2;
}

long long solution(string expression) {
	long long answer = 0;

	vector<long long> num;
	vector<char> op;
	vector<char> op_list = { '*','+','-' }; //오름차순으로 정렬된 값

	long long tmp = 0;
	for (int i = 0; i < expression.length(); i++) {
		long long n = expression[i] - '0';
		if (0 <= n && n <= 9)
			tmp = tmp * 10 + n;
		else {
			op.push_back(expression[i]);
			num.push_back(tmp);
			tmp = 0;
		}
	}
	num.push_back(tmp);

	do {
		vector<long long> num_cp = num;
		vector<char> op_cp = op;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < op_cp.size(); j++) {
				if (op_list[i] == op_cp[j]) {
					num_cp[j] = calc(num_cp[j], num_cp[j + 1], op_cp[j]);
					num_cp.erase(num_cp.begin() + j + 1);
					op_cp.erase(op_cp.begin() + j);
					j--;
				}
			}
		}

		num_cp[0] = abs(num_cp[0]);
		answer = max(answer, num_cp[0]);
	} while (next_permutation(op_list.begin(), op_list.end()));  //순열

	return answer;
}
