class Solution {
public:
    /*int helper(int amt, vector<int>& coins, int ind,vector<vector<int>>& dp){
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
    This approach makes use of Recursion with Memoisation. So it takes TC of O(amt*coins.size())
    And also uses the same for the space complexity.
    By initaialising the base conditions we starting from the minimum possible amount values
    we can solve it in the bottom up approach
    }*/
    int coinChange(vector<int>& coins, int amount){
        if(!amount)return 0;
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i) dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
        }
        return dp[amount]>amount ? -1:dp[amount];
    //This is space optimised bottom up DP/Tabulation DP which makes use of the idea that at 
    //worst case i.e,
    //if the amount isn't achievable that implies we need more coins than the amount itself
    //so we take an array that is initialized with amnt+1. We take min for possible cases
    //So if the amnt is possible then we are left with the ans in dp[amnt] else
    //dp[amnt]>amnt as amnt is initialized with amnt+1.
    //This makes use of the same TC as the previous case but with a space complexity of O(amnt);
    }
};