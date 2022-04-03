class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return;
        int ind1=-1 , i = n-2;
        while(nums[i]>=nums[i+1]){
            i--;
            if(i<0)break;}
        if(i<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        ind1=i;
        i=n-1;
        while(i>=0)
        {
            if(nums[i]>nums[ind1]){
                swap(nums[i],nums[ind1]);
                break;}
            i--;
        }
        reverse(nums.begin()+ind1+1,nums.end());
    }
};