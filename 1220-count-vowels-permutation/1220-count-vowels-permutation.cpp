class Solution {
public:
    unordered_map<int,char> vow;
    int MOD=1e9+7;
    vector<vector<int>> dp;
    
    long long solve(int n, int prev){
        if(n==0){
            return 1;
        }
        if(dp[n][prev]!=-1)return dp[n][prev]%MOD;
        if(prev==0){
            return dp[n][prev] = (solve(n-1,1)%MOD+solve(n-1,2)%MOD+solve(n-1,3)%MOD+solve(n-1,4)%MOD+solve(n-1,5)%MOD)%MOD;
        }
        else if(prev==1){
            return dp[n][prev] = (solve(n-1,prev+1))%MOD;
        }
        else if(prev==2 || prev==4){
            return dp[n][prev] = (solve(n-1,prev-1)%MOD+solve(n-1,prev+1)%MOD)%MOD;
        }
        else if(prev==3){
            return dp[n][prev] = (solve(n-1,1)%MOD+solve(n-1,2)%MOD+solve(n-1,4)%MOD+solve(n-1,5)%MOD)%MOD;
        }
        else{
            return dp[n][prev] = solve(n-1,1)%MOD;
        }
    }
    
    int countVowelPermutation(int n) {
        int i=1;
        vow[i++]='a';
        vow[i++]='e';
        vow[i++]='i';
        vow[i++]='o';
        vow[i++]='u';
        dp.resize(n+1,vector<int>(6,-1));
        return solve(n,0)%MOD;
    }
};