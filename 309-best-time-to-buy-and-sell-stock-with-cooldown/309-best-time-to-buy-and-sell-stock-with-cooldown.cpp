class Solution {
public:
    int solve(vector<int>& prices, vector<vector<int>>& dp, int ind, int buy){
        if(buy==2)buy%=2;
        if(ind>=prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        
        if(buy%2==0){
            int buyVal,leaveVal;
            buyVal=-prices[ind]+solve(prices,dp,ind+1,buy+1);
            leaveVal=solve(prices,dp,ind+1,buy);
            return dp[ind][buy]=max(buyVal,leaveVal);
        }
        else{
            int sellVal,leaveVal;
            sellVal=prices[ind]+solve(prices,dp,ind+2,buy+1);
            leaveVal=solve(prices,dp,ind+1,buy);
            return dp[ind][buy]=max(sellVal,leaveVal);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices, dp, 0,0);
    }
};