class Solution {
public:
    int M,N;
    int dp[1001][1001] = {};
    int mod = 1e9+7;
    
    int dfs(vector<vector<int>>& g, int i, int j , int prev){
        if(i<0 || j<0 || i==M || j==N || g[i][j]<=prev)return 0;
        int cur = g[i][j];
        return dp[i][j]?: dp[i][j] = (1LL + dfs(g, i-1, j, cur) + dfs(g,i+1,j,cur) + dfs(g,i,j-1,cur) + dfs(g,i,j+1,cur))%mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int res=0;
        M=grid.size();
        N=grid[0].size();
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                res = (res + dfs(grid, i, j, 0))%mod;
            }
        }
        return res;
    }
};