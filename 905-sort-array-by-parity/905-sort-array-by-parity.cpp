class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        
        while(i<j){
            bool odd1=nums[i]%2, odd2=nums[j]%2;
            
            if(odd1 && odd2){
                j--;
            }
            
            else if(odd1==0 && odd2==1){
                i++;
                j--;
            }
            
            else if(odd1==1 && odd2==0){
                swap(nums[i++],nums[j--]);
            }
            
            else{
                i++;
            }
        }
        
        return nums;
    }
};