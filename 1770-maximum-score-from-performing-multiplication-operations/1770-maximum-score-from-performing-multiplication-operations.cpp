class Solution{
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = (int)nums.size();
        int m = (int)multipliers.size();
        int dp[m + 1][m + 1] ;
        memset(dp,0,sizeof(dp));
        
        for (int i = m - 1; i >= 0; i--) {
            for (int left = i; left >= 0; left--) {
                int mult = multipliers[i];
                int right = n - 1 - (i - left);
                dp[i][left] = max(mult*nums[left] + dp[i + 1][left + 1], mult*nums[right] + dp[i + 1][left]) ; 
            }
        }
        
        return dp[0][0];
    }
};