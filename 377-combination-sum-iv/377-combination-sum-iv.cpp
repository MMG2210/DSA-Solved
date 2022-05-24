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
    }
    /*int combinationSum4(vector<int>& nums, int target){
        int n=nums.size();
        vector<unsigned int> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int& n:nums){
                if(n<=i)dp[i]+=dp[i-n];
            }
        }
        return dp[target];
    }*/
};