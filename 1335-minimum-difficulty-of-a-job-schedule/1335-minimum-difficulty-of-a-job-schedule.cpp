class Solution {
public:
    int minDifficulty(vector<int>& a, int D) {
        int n=a.size();
        if(n<D)return -1;
        int mx, inf=1e9;
        vector<int> dp(n+1,inf);
        dp[n]=0;
        for(int d=1;d<=D;d++){
            for(int i=0;i<=n-d;i++){
                dp[i]=inf;
                mx=0;
                for(int j=i;j<=n-d;j++){
                    mx=max(mx,a[j]);
                    dp[i] = min(dp[i],mx+dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};