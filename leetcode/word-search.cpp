class Solution {
public:
	bool find_word(int i, int j, int n, vector<vector<bool>>& visit, vector<vector<char>>& board, string word) {
		if (n == word.size()) return true;

		int dy[4] = { -1,1,0,0 };
		int dx[4] = { 0,0,-1,1 };

		int row = board.size();
		int col = board[0].size();

		int ni, nj;
		for (int k = 0; k < 4; k++) {
			ni = i + dy[k];
			nj = j + dx[k];
			if (ni < 0 || nj < 0 || ni >= row || nj >= col) continue;
			if (visit[ni][nj] == true) continue;
			if (word[n] != board[ni][nj]) continue;

			visit[ni][nj] = true;
			if (find_word(ni, nj, n + 1, visit, board, word)) return true;
			visit[ni][nj] = false;
		}

		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == word[0]) {
					vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), 0));
					visit[i][j] = true;
					if (find_word(i, j, 1, visit, board, word)) return true;
				}
			}
		}
		return false;
	}
};
