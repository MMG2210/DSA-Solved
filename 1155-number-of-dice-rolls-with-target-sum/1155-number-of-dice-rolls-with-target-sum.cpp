class Solution {
public:
    const int MOD = 1e9+7;
    int numRollsToTarget(int n, int f, int target) {
        int dp[n+1][target+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                for(int k=1;k<=f;k++){
                    if(k<=j)dp[i][j] = (dp[i][j]%MOD + (dp[i-1][j-k])%MOD)%MOD;
                }
            }
        }
        return dp[n][target];
    }
};