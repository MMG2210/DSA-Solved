class Solution {
public:
    int N;
    
    int solve(vector<string>& strs, int m, int n, int ind,vector<vector<vector<int>>> &dp){
        if(ind==N)return 0;
        if(dp[ind][m][n]!=-1)return dp[ind][m][n];
        
        int cnt1 = count(strs[ind].begin(),strs[ind].end(),'1'), cnt0=count(strs[ind].begin(),strs[ind].end(),'0');
        if(cnt1>n || cnt0>m)
            return dp[ind][m][n] = solve(strs,m,n,ind+1,dp);
        
        else{
            return dp[ind][m][n] = max(solve(strs,m,n,ind+1,dp) , 1 + solve(strs,m-cnt0,n-cnt1,ind+1,dp));
        }
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        N=strs.size();
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        
        return solve(strs,m,n,0,dp);
    }
};