class Solution {
public:
    /*int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dis(n,1);
        int res=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                {
                    dis[i] = max(1+dis[j],dis[i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            res = max(res,dis[i]);
        }
        return res;
    }*/
    int lengthOfLIS(vector<int>& nums){
        vector<int> res;
        for(int &n : nums){
            if(res.empty() || res[res.size()-1]<n)
                res.push_back(n);
            else{
                auto it = lower_bound(res.begin(),res.end(),n);
                *it = n;
            }
        }
        return res.size();
    }
};