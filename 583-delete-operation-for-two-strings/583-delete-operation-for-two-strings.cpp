class Solution {
public:
       int N,M;
//     int minDistance(string word1, string word2) {
//         N=word1.size();
//         M=word2.size();
//         vector<vector<int>> dp(N+1,vector<int>(M+1,-1));
//         int lcs=solve(word1,word2,0,0,dp);
//         return N+M-2*lcs;
//     }
    
//     int solve(string &w1, string& w2, int i, int j, vector<vector<int>>& dp){
//         if(i==N || j==M)return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         if(w1[i]==w2[j])return dp[i][j]=1+solve(w1,w2,i+1,j+1,dp);
//         else return dp[i][j]=max(solve(w1,w2,i+1,j,dp), solve(w1,w2,i,j+1,dp));
//     }
        int minDistance(string w1, string w2) {
            N=w1.size();
            M=w2.size();          
            vector<vector<int>> dp(N+1,vector<int>(M+1));

            for(int i=0;i<=N;i++){
                for(int j=0;j<=M;j++){
                    if(i==0 || j==0)dp[i][j]=0;
                    else if(w1[i-1]==w2[j-1])dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
            return N+M - 2*dp[N][M];
        }   
};