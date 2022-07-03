class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1,0);
        dp[1]=1;
        int share=0, res=0, mod=1e9+7;
        
        for(int i=2;i<=n;i++){
            dp[i] = share = (share + dp[max(0,i-delay)] + mod - dp[max(0,i-forget)])%mod;
        }
        for(int i=n-forget+1;i<=n;i++){
            res = (res + dp[i])%mod;
        }
        return res;
    }
};