class Solution {
public:
    int res=0;
    int mod=1e9+7;
    int dp[51][51][51];
    int solve(int&m , int& n, int moves, int i, int j){
        if(i<0 || i==m || j<0 || j==n){
            return 1;
        }
        if(moves==0)return 0;
        if(dp[i][j][moves]!=-1)return dp[i][j][moves];
        int res=0;
        res = (res + solve(m,n,moves-1,i+1,j)%mod)%mod;
        res = (res + solve(m,n,moves-1,i-1,j)%mod)%mod;
        res = (res + solve(m,n,moves-1,i,j+1)%mod)%mod;
        res = (res + solve(m,n,moves-1,i,j-1)%mod)%mod;
        return dp[i][j][moves]=res;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow,startColumn);
    }
};