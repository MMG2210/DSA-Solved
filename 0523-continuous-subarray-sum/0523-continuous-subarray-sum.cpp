class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m{{0,0}};
        int cur=0;
        for(int i=0;i<nums.size();i++){
            cur+=nums[i];
            if(!m.count(cur%k))m[cur%k]=i+1;
            else if(m[cur%k]<i)return true;
        }
        return false;
    }
};