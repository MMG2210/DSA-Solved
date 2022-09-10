class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        k=k*2
        N = len(prices)
        dp=[]
        for i in range(k+1): dp.append(-100000000)
        dp[0]=0
        
        for j in range(N):
            for i in range(0,k-1,2):
                dp[i+1] = max(dp[i+1],dp[i]-prices[j])
                dp[i+2] = max(dp[i+2],dp[i+1]+prices[j])
        
        return max(dp)