#include <string>
using namespace std;

int solution(string dirs) {
    bool visited[11][11][11][11] = {};
    int dy[4]={-1,1,0,0};
    int dx[4]={0,0,-1,1};

    int answer = 0;
    int si = 5, sj = 5;

    for(char d : dirs) {
        int dir;
        if(d=='U') dir = 0;
        else if(d=='D') dir = 1;
        else if(d=='L') dir = 2;
        else dir = 3;

        int ni, nj;
        ni = si+dy[dir];
        nj = sj+dx[dir];

        if(ni<0 || nj<0 || ni>=11 || nj>=11) continue;

        if(!visited[si][sj][ni][nj]) {
            visited[si][sj][ni][nj] = 1;
            visited[ni][nj][si][sj] = 1;
            answer++;
        }
        si = ni;
        sj = nj;
    }

    return answer;
}
