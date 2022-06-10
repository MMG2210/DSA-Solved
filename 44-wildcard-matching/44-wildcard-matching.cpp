class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    bool solve(string &s, string &p, int i, int j){
        if(j==m)return i==n;
        if(i==n)return (p[j]=='*' && solve(s,p,i,j+1));
        if(dp[i][j]!=-1)return (bool)dp[i][j];
        
        bool cur_match = (i<n && (p[j]=='?' || p[j]==s[i]));
        if(p[j]=='*'){
            return dp[i][j] = solve(s,p,i,j+1) || solve(s,p,i+1,j);
        }
        else return dp[i][j] = cur_match && solve(s,p,i+1,j+1);
    }
    
    bool isMatch(string s, string p) {
        //memset(dp,-1,sizeof(dp));
        n=s.size(), m=p.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(s,p,0,0);
    }
};