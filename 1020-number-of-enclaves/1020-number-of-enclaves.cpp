class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j, int c){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())return 0;
        if(grid[i][j]==2 || grid[i][j]==0)return 0;
        grid[i][j]=c;
        return 1+dfs(grid, i+1, j,c)+dfs(grid, i, j+1,c)+dfs(grid, i-1, j,c)+dfs(grid, i, j-1,c);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[0][i]==1)dfs(grid,0,i,2);
            if(grid[m-1][i]==1)dfs(grid,m-1,i,2);
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==1)dfs(grid,i,0,2);
            if(grid[i][n-1]==1)dfs(grid,i,n-1,2);
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res+=dfs(grid,i,j,0);
            }
        }
        return res;
    }
};