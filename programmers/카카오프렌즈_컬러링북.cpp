#include <vector>
#include <queue>

using namespace std;

int bfs(int i, int j, int m, int n, vector<vector<int>> picture, vector<vector<int>>& visited) {
    int dy[4] = { -1,1,0,0 };
    int dx[4] = { 0,0,-1,1 };

    int size = 0;
    int num = picture[i][j];

    queue<pair<int, int> > q;
    q.push({ i, j });
    visited[i][j] = 1;

    while (!q.empty()) {
        int fi = q.front().first;
        int fj = q.front().second;
        q.pop();
        size++;

        for (int k = 0; k < 4; k++) {
            int ni = fi + dy[k];
            int nj = fj + dx[k];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
            if (visited[ni][nj] || picture[ni][nj] != num) continue;

            q.push({ ni,nj });
            visited[ni][nj] = 1;
        }
    }
    return size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> answer(2);
    vector<vector<int>> visited(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && visited[i][j] == 0) {
                max_size_of_one_area = max(max_size_of_one_area, bfs(i, j, m, n, picture, visited));
                number_of_area++;
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
