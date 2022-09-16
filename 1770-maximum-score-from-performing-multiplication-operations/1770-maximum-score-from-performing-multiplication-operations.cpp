class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& nums, vector<int>& mults, int l, int i) {
        if (i >= mults.size())
            return 0;
        if (dp[l][i]==INT_MIN) {
            int r = nums.size() - 1 - (i - l);
            dp[l][i] = max(nums[l] * mults[i] + dfs(nums, mults, l + 1, i + 1), 
                nums[r] * mults[i] + dfs(nums, mults, l, i + 1));
        }
        return dp[l][i];
    }
    int maximumScore(vector<int>& nums, vector<int>& mults) {
        int m=mults.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return dfs(nums, mults, 0, 0);
    }
};