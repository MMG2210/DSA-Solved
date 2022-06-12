class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res=0,win=0,n=nums.size();
        unordered_set<int> s;
        for(int i=0,j=0;j<n; j++){
            while(s.find(nums[j])!=s.end()){
                win-=nums[i];
                s.erase(nums[i++]);
            }
            
            win+=nums[j];
            s.insert(nums[j]);
            res=max(win,res);
        }
        return res;
    }
};