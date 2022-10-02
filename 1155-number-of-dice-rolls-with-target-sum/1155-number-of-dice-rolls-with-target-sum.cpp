#define ll long long
class Solution {
public:
    const int MOD = 1e9+7;
    int N,K;
    vector<vector<int>> dp;
    int solve(int ind, int target){
        if(ind==0 && target==0)return 1;
        if(ind==0 || target<0)return 0;
        if(dp[ind][target]!=-1)return dp[ind][target];
        int res=0;
        for(int i=1;i<=K;i++){
            res=(res%MOD+solve(ind-1,target-i)%MOD)%MOD;
        }
        return dp[ind][target]=res;
    }
    int numRollsToTarget(int n, int k, int target) {
        K=k;
        dp.assign(n+1,vector<int>(target+1,-1));
        return solve(n,target);
    }
};