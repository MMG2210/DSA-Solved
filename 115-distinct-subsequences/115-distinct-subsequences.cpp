class Solution {
public:
    int helper(string s, string t, int l1, int l2, vector<vector<int>>& dp){
        if(l2<0)return 1;
        if(l1<0)return 0;
        if(dp[l1][l2]!=-1)return dp[l1][l2];
        if(s[l1]!=s[l2])return dp[l1][l2]=helper(s,t,l1-1,l2,dp);
        else{
            return dp[l1][l2]=helper(s,t,l1-1,l2-1,dp)+helper(s,t,l1-1,l2,dp);
        }
    }
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long>(n+1,-1));
        for(int i=0;i<=n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=m;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i][j-1] + (s[j-1]==t[i-1]?dp[i-1][j-1]:0);
            }
        }
        return dp[m][n];
    }
};