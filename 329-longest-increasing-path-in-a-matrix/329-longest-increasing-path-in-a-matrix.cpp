class Solution {
public:
    int res=INT_MIN;
    int mod = 1e9+7;
    
    int dp[201][201];
    
    bool isInvalid(vector<vector<int>>& matrix, int i, int j){
        return i<0 || j<0 || i>matrix.size()-1 || j>matrix[i].size()-1;
    }
    
    int dfs(vector<vector<int>>& matrix, int i, int j, int prev){
        if(isInvalid(matrix,i,j) || prev>=matrix[i][j])return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int len=0;
        len=max(len,dfs(matrix, i-1, j, matrix[i][j]));
        len=max(len,dfs(matrix, i+1, j, matrix[i][j]));
        len=max(len,dfs(matrix, i, j-1, matrix[i][j]));
        len=max(len,dfs(matrix, i, j+1, matrix[i][j]));
        return dp[i][j] = (1+len)%mod;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,dfs(matrix,i,j,-1));
            }
        }
        
        return res;
    }
};