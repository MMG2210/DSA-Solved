class Solution {
private:
    int dp[30002][2];
    int helper(vector<int>& prices, int ind, int buy){
        if(ind == prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy){
            return dp[ind][buy]=max(-prices[ind]+helper(prices,ind+1,0),helper(prices,ind+1,1));
        }
        else{
            return dp[ind][buy]=max(prices[ind]+helper(prices,ind+1,1),helper(prices,ind+1,0));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return helper(prices,0,1);
        //return dp[prices.size()-1][1];
    }
};