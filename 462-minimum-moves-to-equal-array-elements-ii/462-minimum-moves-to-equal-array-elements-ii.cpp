class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res=0, n=nums.size();
        sort(nums.begin(),nums.end());
        int mid = nums[n/2];
        int l=0,r=n-1;
        // for(int i=0;i<n;i++){
        //     res+=abs(nums[i]-mid);
        // }
        while(l<r){
            res+=nums[r--]-nums[l++];
        }
        return res;
    }
};