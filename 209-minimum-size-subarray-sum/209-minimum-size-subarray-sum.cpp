class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curSum=0,res=INT_MAX, start=0;
        for(int end=0;end<nums.size();end++){
            curSum+=nums[end];
            while(curSum>=target){
                res=min(res,end-start+1);
                if(res==1)return res;
                curSum-=nums[start++];
            }
        }
        
        return res==INT_MAX?0:res;
    }
};