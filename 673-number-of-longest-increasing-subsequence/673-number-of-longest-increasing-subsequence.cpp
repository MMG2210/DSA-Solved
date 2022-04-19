class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),maxL=1,res=0;
        vector<int> dp(n+1,1),cnt(n+1,1);
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                    maxL=max(maxL,dp[i]);
                }
                else if(nums[j]<nums[i] && dp[j]+1==dp[i]){
                    cnt[i]+=cnt[j];
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i]==maxL)res+=cnt[i];
        }
        return res;
    }
};