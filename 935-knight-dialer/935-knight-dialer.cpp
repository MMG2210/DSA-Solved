class Solution {
public:
    int mod = 1e9+7;
    
    int solve(int i, int j, int n, vector<vector<vector<int>>> &dp){
        if(i<0 || j<0 || i>=4 || j>=3 || (i==3 && j!=1))return 0;
        if(n==1)return 1;
        if(dp[n][i][j]!=-1)return dp[n][i][j];
        long long cnt=0;
        cnt = (cnt + 
               solve(i-2,j-1,n-1,dp)%mod
              + solve(i-1,j-2,n-1,dp)%mod
              +solve(i-2,j+1,n-1,dp)%mod
              +solve(i-1,j+2,n-1,dp)%mod
              +solve(i+2,j-1,n-1,dp)%mod
              + solve(i+1,j-2,n-1,dp)%mod
              +solve(i+2,j+1,n-1,dp)%mod
              +solve(i+1,j+2,n-1,dp)%mod
               )%mod;
        return dp[n][i][j] = cnt;
    }
    
    int knightDialer(int n) {
        long long res=0;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(4,vector<int>(3,-1)));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                res = (res + solve(i, j, n, dp)%mod)%mod;
            }
        }
        
        return res%mod;
    }
};