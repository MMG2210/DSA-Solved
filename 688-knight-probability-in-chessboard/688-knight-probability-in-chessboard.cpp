class Solution {
public:
    /*for(int i=0;i<8;i++){
            int new_r=r+dy[i];
            int new_c=r+dx[i];
            res+=solve(new_r,new_c,new_k,n,dp);
        }*/
    bool isValid(int r, int c, int n){
        return r>=0 && r<n && c>=0 && c<n; 
    }
    
    double solve(int r, int c, int k, int n, vector<vector<vector<double>>>& dp){
        if(!isValid(r,c,n))return 0;
        if(k==0)return 1;
        if(dp[r][c][k]!=-1)return dp[r][c][k];
        double res=0.0;
        int new_k=k-1;
        res=solve(r-2,c-1,k-1,n,dp)+solve(r-1,c-2,k-1,n,dp)+solve(r+1,c-2,k-1,n,dp)+solve(r+2,c-1,k-1,n,dp)+solve(r-2,c+1,k-1,n,dp)+solve(r-1,c+2,k-1,n,dp)+solve(r+2,c+1,k-1,n,dp)+solve(r+1,c+2,k-1,n,dp);
        res/=8.0;
        return dp[r][c][k]=res;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return solve(row,column,k,n,dp);
    }
};