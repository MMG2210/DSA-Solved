class Solution {
public:
    int helper(int i, int j,int m, int n, vector<vector<int>> &dp)
    {
        if(i>=m || j>=n)return 0;
        if(i==m-1 && j==n-1)return dp[i][j]=1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        else return dp[i][j] = helper(i+1,j,m,n,dp)+helper(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
        //memset(dp,-1,sizeof(dp));
        return helper(0,0,m,n,dp);
        // int N = m+n-2;
        // int r = m-1;
        // double res = 1;
        // for(int i = 1 ; i<=r ; i++)
        //     res=res*(N-r+i)/i;
        // return (int)res;
    }
};