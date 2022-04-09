class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || grid[i][j])return 0;
        
        grid[i][j]=1;
        return grid[i][j]+dfs(grid,i+1,j)+dfs(grid,i,j+1)+dfs(grid,i-1,j)+dfs(grid,i,j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i*j==0 || i==m-1 || j==n-1)dfs(grid,i,j);
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){res++;dfs(grid,i,j);}
            }
        }
        return res;
    }
};