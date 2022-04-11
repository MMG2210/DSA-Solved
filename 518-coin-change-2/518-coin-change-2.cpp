class Solution {
public:
    int helper(vector<int>& coins, vector<vector<int>>& dp, int i, int amnt){
        if(i<0)return 0;
        if(amnt==0)return 1;
        if(dp[i][amnt]!=-1)return dp[i][amnt];
        if(coins[i]>amnt)return dp[i][amnt] = helper(coins,dp,i-1,amnt);
        else{
            return dp[i][amnt]=helper(coins,dp,i,amnt-coins[i])+helper(coins,dp,i-1,amnt);
        }
    }
    int change(int amount, vector<int>& coins) {
        //int n=coins.size();
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,-1));
        return helper(coins,dp,coins.size()-1,amount);
    }
};