class Solution {
public:
    int MOD=1e9+7;
    int dp[1001][1001];
    
    int solve(int n, int k){
        if(k<=0)return !k;
        if(n<=0)return 0;
        if(dp[n][k]!=-1)return dp[n][k];
        
        dp[n][k] = (solve(n-1,k) + solve(n,k-1))%MOD;
        return dp[n][k] = (dp[n][k]+(MOD-solve(n-1,k-n))%MOD)%MOD;
    }
    
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};