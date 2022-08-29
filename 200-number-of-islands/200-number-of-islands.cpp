class Solution {
public:
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,1,-1};
    void dfs(vector<vector<char>>& grid , int i, int j, vector<vector<bool>>& vis){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nx = i+dx[k], ny = j+dy[k];
            if(nx<grid.size() && ny<grid[0].size() && nx>=0 && ny>=0 && grid[nx][ny]=='1' && !vis[nx][ny]){
                dfs(grid, nx, ny, vis);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res=0, n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    res++;
                    dfs(grid, i, j, vis);
                }
            }
        }
        return res;
    }
};