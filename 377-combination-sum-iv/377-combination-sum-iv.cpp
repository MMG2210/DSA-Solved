class Solution {
public:
    int solve(vector<int>& nums, int ind, int trgt, vector<vector<int>>& dp){
        if(trgt==0)return 1;
        if(ind==nums.size())return 0;
        if(dp[ind][trgt]!=-1)return dp[ind][trgt];
        if(nums[ind]>trgt)return dp[ind][trgt] = solve(nums,ind+1,trgt,dp);
        return dp[ind][trgt] = solve(nums,0,trgt-nums[ind],dp)+solve(nums,ind+1,trgt,dp);
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));
        return solve(nums,0,target,dp);
        /*for(int i=0;i<nums.size();i++){
            dp[i][0]=1;
        }
        for(int i=0;i<=target;i++)
            dp[n][i]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=target;j++){
                if(nums[i]>j){
                    dp[i][j]=
                }
            }
        }*/
    }
};