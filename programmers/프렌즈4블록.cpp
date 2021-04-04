#include <string>
#include <vector>
#include <stack>

using namespace std;

void down(int m, int n, vector<string> &board, vector<vector<bool>> visit) {
    for (int j = 0; j < n; j++) {
        stack<char> st;
        for (int i = 0; i < m; i++) {
            if (visit[i][j]) continue;
            st.push(board[i][j]);
        }

        int i = m - 1;
        while (!st.empty()) {
            char c = st.top();
            st.pop();
            board[i][j] = c;
            i--;
        }
        while (i >= 0) {
            board[i][j] = '*';
            i--;
        }
    }
}

int find(int m, int n, vector<string> &board) {
    int ret = 0;
    vector<vector<bool>> visit(m, vector<bool>(n, 0));
    int dy[4] = { 0,1,0,1 };
    int dx[4] = { 0,0,1,1 };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c = board[i][j];
            if (board[i][j] == '*') continue;

            int k;
            for (k = 1; k < 4; k++) {
                int ni = i + dy[k];
                int nj = j + dx[k];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n || board[ni][nj] != c ) {
                    break;
                }
            }

            if (k == 4) {
                for (k = 0; k < 4; k++) {
                    int ni = i + dy[k];
                    int nj = j + dx[k];
                    if (!visit[ni][nj]) {
                        visit[ni][nj] = 1;
                        ret++;
                    }
                }
            }
        }
    }

    if (ret) {
        down(m, n, board, visit);
    }

    return ret;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (1) {
        int ret = find(m, n, board);
        if (!ret) break;
        answer += ret;
    }

    return answer;
}
