class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(2,1));
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j] && dp[i][0] < 1+dp[j][1])dp[i][0]=dp[j][1]+1;
                else if(a[i]<a[j] && dp[i][1] < 1 + dp[j][0])dp[i][1] = dp[j][0]+1;
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};