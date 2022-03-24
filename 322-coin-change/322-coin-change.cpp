class Solution {
public:
    int helper(int amt, vector<int>& coins, int ind,vector<vector<int>>& dp){
        if(dp[ind][amt]!=-1)return dp[ind][amt];
        if(ind==0 || amt==0)return amt==0 ? 0:INT_MAX-1;
        if(amt<coins[ind-1]){
            return dp[ind][amt] = helper(amt,coins,ind-1,dp);
        }
        else{
            return dp[ind][amt] = min(1+helper(amt-coins[ind-1],coins,ind,dp),helper(amt,coins,ind-1,dp));
        }
    }
    int coinChange(vector<int>& coins, int amt) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amt+1,-1));
        int minCoins = helper(amt,coins,coins.size(),dp);
        return minCoins==INT_MAX-1?-1:minCoins;
    }
};