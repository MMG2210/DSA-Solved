class Solution {
public:
    int n;
    
    int solve(string &s, string &s1, int i, int j, vector<vector<int>> &dp){
        if(i==n || j==n)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i]!=s1[j])return dp[i][j]=max(solve(s,s1,i+1,j,dp), solve(s,s1,i,j+1,dp));
        else{
            return dp[i][j]=1+solve(s,s1,i+1,j+1,dp);
        }
    }
    
    int longestPalindromeSubseq(string s) {
        string s1=s;
        n=s.size();
        reverse(s1.begin(),s1.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s,s1,0,0,dp);
    }
};