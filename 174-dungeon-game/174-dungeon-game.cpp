class Solution {
public:
    int m,n;
    int recurse(vector<vector<int>>& dungeon,int i, int j, vector<vector<int>>& dp){
        if(i==m || j==n)return 1e9;
        
        if(i==m-1 && j==n-1){
            return dungeon[i][j]<=0?(1-dungeon[i][j]):1;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int right=recurse(dungeon,i,j+1,dp);
        int down=recurse(dungeon,i+1,j,dp);
        int res=min(right,down)-dungeon[i][j];
        return dp[i][j] = res<=0?1:res;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n=dungeon[0].size();
        m=dungeon.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return recurse(dungeon,0,0,dp);
    }
};