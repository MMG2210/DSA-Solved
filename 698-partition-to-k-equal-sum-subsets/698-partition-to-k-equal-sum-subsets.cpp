class Solution {
private:
    int sum, all, n;
    vector<int> memo;
    
    bool isPossible(vector<int>& nums, int k, int mask, int curr) {
        if(curr == sum) {
            k--;
            curr = 0;
        }
        
        if(k < 0 || curr > sum) return false; // Pruning
        if(mask == all) return k == 0 && curr == 0; // All elements are used
        
        if(memo[mask] != -1) return memo[mask];
        
        bool ans = false;
        for(int i = 0; i<n; i++) {
            if((mask & (1 << i)) == 0) ans = ans || isPossible(nums, k, mask | (1 << i), curr+nums[i]); // Using the ith element if not already used.
        }
        
        return memo[mask] = ans;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size(), all = (1 << n) - 1, sum = accumulate(nums.begin(), nums.end(), 0);
        int mask = 0;
        
        memo = vector<int>(all, -1);
        
        if(sum%k != 0) return false;
        else sum /= k;
        
        return isPossible(nums, k, mask, 0);
    }
};