class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount=0;
        for(int& n:nums)if(n==0)zeroCount++;
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)nums[j++]=nums[i];
        }
        j=nums.size()-1;
        while(zeroCount--){
            nums[j--]=0;
        }
    }
};