#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length();
    int len2 = len - k;

    int index = -1;
    char num;
    for(int i=0;i<len2;i++){
        num = '0';

        int j = index+1;
        for(j;j<=k+i;j++){
            if(num < number[j]){
                num = number[j];
                index = j;
            }
        }
        answer += num;
    }

    return answer;
}
