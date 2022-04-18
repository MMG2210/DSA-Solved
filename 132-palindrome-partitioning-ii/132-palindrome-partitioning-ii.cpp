class Solution {
public:
    bool isPalin(string& s, int st, int e){
        //int l=0,r=s.size()-1;
        while(st<e){
            if(s[st++]!=s[e--])return false;
        }
        return true;
    }
    
    int helper(string& s,int i, int j, vector<vector<int>>& dp){
        if(i>=j)return dp[i][j] = 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(isPalin(s,i,j))return dp[i][j] = 0;
        int res=INT_MAX;
        for(int k=i;k<=j-1;k++){
            if(!isPalin(s,i,k))continue;
            int temp=1+helper(s,i,k,dp)+helper(s,k+1,j,dp);
            res=min(res,temp);
        }
        return dp[i][j]=res;
    }
    
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(s,0,n-1,dp);
        //return dp[0][n];
    }
};