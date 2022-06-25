class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int shift=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                shift++;
                if(i-2<0 || nums[i-2]<=nums[i])nums[i-1]=nums[i];
                else nums[i]=nums[i-1];
            }
        }
        
        return shift<=1;
    }
};