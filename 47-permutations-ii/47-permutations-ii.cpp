class Solution {
public:
    vector<vector<int>> res;
    int size;
    
    void recur(vector<int> nums, int ind){
        if(ind==size-1){
            res.push_back(nums);
            return;
        }
        
        for(int i=ind;i<size;i++){
            if(i!=ind && nums[i]==nums[ind])continue;
            swap(nums[i],nums[ind]);
            recur(nums,ind+1);
            //temp.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        size=nums.size();
        recur(nums,0);
        return res;
    }
};