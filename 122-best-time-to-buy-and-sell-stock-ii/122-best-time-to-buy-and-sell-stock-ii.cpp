class Solution {
/*private:
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
        //Recursion with memoisation TC = O(N*2) and SC = O(N)
    }*/
public:
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        int nextBuy=0,nextNotBuy=0;
        int curBuy=0,curNotBuy=0;
        for(int i=n-1;i>=0;i--){
            curNotBuy = max(prices[i]+nextBuy,nextNotBuy);
            curBuy = max(-prices[i]+nextNotBuy,nextBuy);
            nextBuy=curBuy;
            nextNotBuy=curNotBuy;
        }
        return curBuy;
    }
};