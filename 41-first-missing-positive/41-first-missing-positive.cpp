class Solution {
public:
    //int firstMissingPositive(vector<int>& nums) {
    //     unordered_set<int> s;
    //     for(int& n:nums){
    //         if(n>0)s.insert(n);
    //     }
    //     for(int i=1;i<1e9;i++){
    //         if(s.find(i)==s.end())return i;
    //     }
    //     return -1;
    // }
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)if(nums[i]<=0)nums[i]=n+1;
        for(int i=0;i<n;i++)if(abs(nums[i])<=n && nums[abs(nums[i])-1]>0)nums[abs(nums[i])-1]*=-1;
        for(int i=0;i<n;i++)if(nums[i]>0)return i+1;
        return n+1;
    }
};