class Solution {
public:
    int M, N;
    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row==M)return col;
        int ncol = col+grid[row][col];
        if(ncol<0 || ncol>N-1 || grid[row][col]!=grid[row][ncol])return -1;
        return dfs(grid, row+1, ncol);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        M = grid.size(), N=grid[0].size();
        vector<int> res;
        for(int j=0;j<N;j++){
            res.push_back(dfs(grid,0,j));
        }
        return res;
    }
};