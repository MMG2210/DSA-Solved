class Solution {
public:
//     int dp[101][101];
    
//     bool solve(string &s1, string &s2, string &s3,int l1, int l2, int n){
//         if(l1<0 && l2<0 && n<0)return true;
//         if(l1>=0 && l2>=0 && dp[l1][l2]!=-1)return dp[l1][l2];
//         if(l1>=0 && s1[l1]==s3[n] && l2>=0 && s2[l2]==s3[n])
//             return dp[l1][l2]=solve(s1,s2,s3,l1-1,l2,n-1)||solve(s1,s2,s3,l1,l2-1,n-1);
//         else if(l1>=0 && s1[l1]==s3[n])
//             return solve(s1,s2,s3,l1-1,l2,n-1);
//         else if(l2>=0 && s2[l2]==s3[n])
//             return solve(s1,s2,s3,l1,l2-1,n-1);
//         return false;
//     }
    
//     bool isInterleave(string s1, string s2, string s3) {
//         if(s3.size()!=s1.size()+s2.size())return false;
//         memset(dp,-1,sizeof(dp));
//         return solve(s1,s2,s3,s1.size()-1,s2.size()-1,s3.size()-1);
//     }
// Method = Recursion with Memoisation TC = O(M*N), SC = O(M*N), AUX Stack Space = O(M*N) 
    
    
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.length(), n=s2.length(), L=s3.length();
        if(n+m!=L)return false;
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        //When all strings are empty
        dp[0][0]=1;
        
        //If m==0 then only possible if s2==s3
        for(int j=1;j<=n;j++){
            dp[0][j]=dp[0][j-1]&&s2[j-1]==s3[j-1];
        }
        
        //If n==0, then only possiblity is if s1==s3
        for(int i=1;i<=m;i++){
            dp[i][0]=dp[i-1][0]&&s1[i-1]==s3[i-1];
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                bool takeFromS1 = dp[i-1][j] && s1[i-1]==s3[i+j-1];
                bool takeFromS2 = dp[i][j-1] && s2[j-1]==s3[i+j-1];
                dp[i][j]=takeFromS1||takeFromS2;
            }
        }
        
        return dp[m][n];
    }
    // Method = Tabulation, TC - O(m*n), SC - O(m*n)
};