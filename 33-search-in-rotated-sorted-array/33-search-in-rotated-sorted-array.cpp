class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int m=0;
        while(l<h)
        {
            m = (l+h)/2;
            if ((nums[0]>target)^(nums[0]>nums[m])^(target>nums[m]))
                l=m+1;
            else h=m;
        }
        return ((l==h) && nums[l]==target ? l : -1);
    }
};