class Solution {
public:
    
    int solve(vector<int>& prices, int kt, int ind, int cur, vector<vector<int>>& dp){
        if(cur==kt)return 0;
        if(ind==prices.size())return 0;
        
        if(dp[ind][cur]!=-1)return dp[ind][cur];
        
        if(cur%2==0){//We can buy
            int buyVal,leaveVal;
            buyVal=-prices[ind]+solve(prices,kt,ind+1,cur+1,dp);
            leaveVal=solve(prices,kt,ind+1,cur,dp);
            return dp[ind][cur] = max(buyVal,leaveVal);
        }
        else{
            int sellVal,leaveVal;
            sellVal=prices[ind]+solve(prices,kt,ind+1,cur+1,dp);
            leaveVal=solve(prices,kt,ind+1,cur,dp);
            return dp[ind][cur] = max(sellVal,leaveVal);
        }
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        //vector<vector<vector<int>>> dp(prices.size()+1,vector<int>(k+1,vector<int>(2,-1)));
        int kt=2*k;
        vector<vector<int>> dp(prices.size()+1,vector<int>(kt,-1));
        return solve(prices,kt,0,0,dp);
    }
};