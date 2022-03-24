class Solution {
public:
    bool isPerfectSqr(int x){
    if (x >= 0) {
        long long sr = sqrt(x);
        return (sr * sr == x);
        }
    return false;
    }
    /*int helper(int target,int cosN){
        //if(dp[target][cosN]!=-1)return dp[target][cosN];
        if(!target)return 0;
        if(target==1)return 1;
        if(cosN==1)return target;
        if(cosN>target)cosN=target;
        if(!isPerfectSqr(cosN))return helper(target, cosN-1);
        else 
            return min(1+helper(target-cosN,cosN),helper(target, cosN-1));
    }*/
    int helper(int target,int cosN,vector<int>& dp){
        if(dp[target]!=-1)return dp[target];
        if(target<=3)return dp[target]  = target;
        //if(!target)return dp[target] = 0;
        if(cosN==1)return dp[target] = target;
        //if(target==1)return dp[target] = 1;
        if(cosN>target)cosN=target;
        if(!isPerfectSqr(cosN))return dp[target] = helper(target, cosN-1,dp);
        else 
            return dp[target] = min(1+helper(target-cosN,cosN,dp),helper(target, cosN-1,dp));
    }
    /*int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,n,dp);
    }*/
    int numSquares(int n) {
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int minVal=INT_MAX;
            for(int j=1;j*j<=i;j++){
                minVal=min(minVal,dp[i-j*j]);
            }
            dp[i]=minVal+1;
        }
        return dp[n];
    }
};