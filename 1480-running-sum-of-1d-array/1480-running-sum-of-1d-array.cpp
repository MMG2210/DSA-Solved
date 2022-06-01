class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> preSum(n,0);
//         preSum[0]=nums[0];
//         for(int i=1;i<n;i++){
//             preSum[i]=nums[i]+preSum[i-1];
//         }
        
//         return preSum;
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        
        return nums;
    }
};