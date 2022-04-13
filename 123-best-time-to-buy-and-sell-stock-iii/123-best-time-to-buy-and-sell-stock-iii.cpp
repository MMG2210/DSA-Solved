class Solution {
public:
    int helper(vector<int>& prices, vector<vector<int>> &dp, int i, int buy){
        if(i==prices.size())return 0;
        if(buy==4)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        
        if(buy%2==0){
            return dp[i][buy]=max(helper(prices,dp,i+1,buy),-prices[i]+helper(prices,dp,i+1,buy+1));
        }
        else{
            return dp[i][buy]=max(helper(prices,dp,i+1,buy),prices[i]+helper(prices,dp,i+1,buy+1));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(4,-1));
        return helper(prices,dp,0,0);
    }
};