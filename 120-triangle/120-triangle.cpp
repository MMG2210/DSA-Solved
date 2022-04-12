class Solution {
public:
    int util(vector<vector<int>>& triangle, int h, int j, vector<vector<int>>& dp){
        if(h==triangle.size())return 0;
        if(dp[h][j]!=-1)return dp[h][j];
        return dp[h][j]=triangle[h][j]+min(util(triangle,h+1,j,dp),util(triangle,h+1,j+1,dp));
    }
    int minimumTotal(vector<vector<int>>& T) {
        for (int i = T.size() - 2; ~i; i--) 
            for (int j = T[i].size() - 1; ~j; j--) 
                T[i][j] += min(T[i+1][j], T[i+1][j+1]);
        return T[0][0];
    }
};