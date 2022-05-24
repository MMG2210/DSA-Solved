class Solution {
public:
    
    int solve(vector<int> nums){
        int prev=nums[0],prev2=0;
        for(int i=1;i<nums.size();i++){
            int cur = prev2+nums[i];
            prev2 = prev;
            prev = max(prev,cur);
        }
        
        return prev;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int pickFirst=solve(vector<int>(nums.begin(),nums.end()-1));
        int pickLast=solve(vector<int>(nums.begin()+1,nums.end()));
        return max(pickFirst,pickLast);
    }
};