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
    //This approach uses DP so it takes TC of O(N^2) and SC of O(N)
    int lengthOfLIS(vector<int>& nums){
        vector<int> res;
        for(int &n : nums){
            if(res.empty() || res[res.size()-1]<n)
                res.push_back(n);
            else{
                int it = lower_bound(res.begin(),res.end(),n)-res.begin();
                res[it] = n;
            }
        }
        return res.size();
    }
    //This approach use Binary Search inside the resultant subsequence array to find the smallest number that is greater than n and replaces n with that number. This works because we assume that it is the best to keep the smallest number in the subsequence for the possiblity of the sequence becoming the largest.
};