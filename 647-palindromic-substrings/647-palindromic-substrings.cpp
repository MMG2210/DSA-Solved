class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int solve(string& s, int i, int j){
        if(i>=j)return 1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i]!=s[j])return dp[i][j] = 0;
        else{
            return dp[i][j] = solve(s,i+1,j-1);
        }
    }
    
    int countSubstrings(string s) {
        n=s.size();
        dp.resize(n,vector<int>(n,-1));
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                res+=solve(s,i,j);
            }
        }
        return res;
    }
};