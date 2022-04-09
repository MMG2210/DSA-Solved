class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(), res=INT_MAX;
        if(grid[0][0] || grid[n-1][n-1])return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        pair<int, int> dirs[8] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1,1}, {-1,-1}, {1,-1}, {1,1} };
        while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();
            if(cur.first==n-1 && cur.second==n-1)return grid[n-1][n-1];
			for (auto& dir : dirs) {
				int nx = dir.first + cur.first;
				int ny = dir.second + cur.second;
				if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 0) {
					q.push({ nx, ny });
					grid[nx][ny] = grid[cur.first][cur.second] + 1;
				}
			}
		}
        return -1;
    }
};