class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int rsum=0;
        for(int& i:nums){
            if(!(i&1))rsum+=i;
        }
        for(auto& q:queries){
            int i=q[1],val=q[0];
            if(nums[i]%2==0 && val%2==0)rsum+=val;
            else if(nums[i]%2 && val%2)rsum+=(nums[i]+val);
            else if(nums[i]%2==0 && val%2)rsum-=nums[i];
            nums[i]+=val;
            res.push_back(rsum);
        }
        return res;
    }
};