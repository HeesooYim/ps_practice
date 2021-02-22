#include <numeric>
using namespace std;

long long solution(int w, int h) {
	long long answer = 1;
	long long g = gcd(w, h);
	answer = ((long long)w*(long long)h) - ((long long)w + (long long)h - g);
	// (w*h) - ((w/g) + (h/g) - 1)
	return answer;
}
