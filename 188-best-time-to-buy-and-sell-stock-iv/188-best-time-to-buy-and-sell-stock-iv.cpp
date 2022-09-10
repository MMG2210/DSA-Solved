class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int kt=2*k,N=prices.size();
        vector<int> memo(kt+1,INT_MIN);
        memo[0]=0;
        
        for(int j=0;j<N;j++){
            for(int i=0;i+2<=kt;i+=2){
                memo[i+1]=max(memo[i+1],memo[i]-prices[j]);
                memo[i+2]=max(memo[i+2],memo[i+1]+prices[j]);
            }
        }
        
        return *max_element(memo.begin(),memo.end());
    }
};