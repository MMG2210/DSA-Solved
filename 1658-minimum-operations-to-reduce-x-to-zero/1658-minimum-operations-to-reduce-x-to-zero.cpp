class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int l=0,r=0,sum=0;
        for(int& i:nums)sum+=i;
        int req=sum-x, res=INT_MIN, curr=0;
        if(req<0)return -1;
        for(;r<n;r++){
            curr+=nums[r];
            while(curr>req && l<=r){
                curr-=nums[l++];
            }
            if(curr==req)res=max(res,r-l+1);
        }
        return res==INT_MIN?-1:n-res;
    }
};