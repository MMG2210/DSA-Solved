class Solution {
public:
    int solve(vector<int>& nums, int l, int r, vector<vector<int>>& dp){
        if(l>=r)return 0;
        //if(l==r)return nums[l];
        if(dp[l][r]!=-1)return dp[l][r];
        int res=INT_MIN;
        for(int k=l;k<r;k++){
            int temp = solve(nums,l,k,dp)+solve(nums,k+1,r,dp)+nums[k]*nums[l-1]*nums[r];
            res=max(temp,res);
            dp[l][r]=res;
        }
        return dp[l][r] = res;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return solve(nums,1,nums.size()-1,dp);
        
        /*dp[0][0]=nums[0];
        //dp[nums.size()-1][]
        for(int l=1;l<=nums.size();l++){
            for(int r=nums.size()-1;r>=0;r--){
                int temp=INT_MIN;
                for(int k=l;k<=r;k++){
                    int t2 = 
                }
            }
        }*/
    }
};