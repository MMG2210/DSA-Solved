class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy(nums.begin(),nums.end());
        int n=nums.size();
        int res=0, flag=0;
        sort(copy.begin(),copy.end());
        for(int i=0; i<n; i++){
            if(nums[i]!=copy[i]){
                res-=i;
                flag++;
                break;
            }
        }
        
        if(!flag)return 0;
        
        for(int i=n-1;i>-1;i--){
            if(nums[i]!=copy[i]){
                res+=i;
                break;
            }
        }
        
        return res+1;
    }
};