class Solution {
public:
    int m,n;
    int dfs(vector<vector<int>>& OG, int i, int j){
        if(i==m || j==n || OG[i][j]==1)return 0;
        if(i==m-1 && j==n-1)return 1;
        
        //OG[i][j]=1;
        return dfs(OG,i+1,j)+dfs(OG,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& OG) {
        m=OG.size();
        n=OG[0].size();
        //return dfs(OG,0,0);
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            if(OG[i][0]!=1)dp[i][0]=1;
            else break;
        }
        for(int i=0;i<n;i++){
            if(OG[0][i]!=1)dp[0][i]=1;
            else break;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(OG[i][j]!=1){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};