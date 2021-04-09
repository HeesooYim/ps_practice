int visit[302][302];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
void bfs(int i, int j, char** grid, int gridSize, int* gridColSize) {
	int queue[90002][2];
	int front = 0;
	int rear = 0;

	queue[0][0] = i;
	queue[0][1] = j;
	rear++;
	visit[i][j] = 1;

	while (front < rear) {
		int fi = queue[front][0];
		int fj = queue[front][1];
		front++;

		for (int i = 0; i < 4; i++) {
			int ni = fi + dy[i];
			int nj = fj + dx[i];
			if (ni < 0 || nj < 0 || ni >= gridSize || nj >= *gridColSize || visit[ni][nj] || grid[ni][nj]=='0')
				continue;
			queue[rear][0] = ni;
			queue[rear][1] = nj;
			rear++;
			visit[ni][nj] = 1;
		}
	}
}
 
int numIslands(char** grid, int gridSize, int* gridColSize) {
	int ret = 0;
    memset(visit, 0, sizeof(visit));
    
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			if (grid[i][j]=='1' && visit[i][j]==0) {
				ret++;
				bfs(i, j, grid, gridSize, gridColSize);
			}
		}
	}

	return ret;
}
