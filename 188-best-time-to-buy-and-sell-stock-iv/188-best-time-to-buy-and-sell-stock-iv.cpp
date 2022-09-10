class Solution {
public:
    vector<vector<int>> dp;
    int N,kt;
    
    int solve(int ind, int cur, vector<int>& p){
        if(cur>kt || ind==N)return 0;
        if(dp[cur][ind]!=-1)return dp[cur][ind];
        int act = p[ind]*(cur&1?1:-1)+solve(ind+1,cur+1,p);
        int hold = solve(ind+1,cur,p);
        return dp[cur][ind]=max(act,hold);
    }
    
    int maxProfit(int k, vector<int>& prices) {
        kt=2*k, N=prices.size();
        dp.resize(kt+1,vector<int>(N+1,-1));
        
        vector<int> memo(kt+1,INT_MIN);
        memo[0]=0;
        
        for(int j=0;j<N;j++){
            for(int i=0;i+2<=kt;i+=2){
                memo[i+1]=max(memo[i+1],memo[i]-prices[j]);
                memo[i+2]=max(memo[i+2],memo[i+1]+prices[j]);
            }
        }
        
        return *max_element(memo.begin(),memo.end());
        return solve(0,0,prices);
    }
};