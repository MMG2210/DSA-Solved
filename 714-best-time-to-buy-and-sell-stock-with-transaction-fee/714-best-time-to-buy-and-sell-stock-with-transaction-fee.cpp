class Solution {
public:
    int f,n;
    
    int solve(vector<int>& prices, vector<vector<int>> &dp, int ind, int buy){
        if(ind==n)return 0;
        if(buy==2)buy%=2;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        
        if(buy%2==0){
            int buyVal,skipVal;
            buyVal=-prices[ind]+solve(prices,dp,ind+1,buy+1);
            skipVal=solve(prices,dp,ind+1,buy);
            return dp[ind][buy]=max(buyVal,skipVal);
        }
        else{
            int sellVal,skipVal;
            sellVal=prices[ind]+solve(prices,dp,ind+1,buy+1)-f;
            skipVal=solve(prices,dp,ind+1,buy);
            return dp[ind][buy]=max(sellVal,skipVal);
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        f=fee;
        n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(prices,dp,0,0);
    }
};