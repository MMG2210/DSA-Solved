class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cntNeg=0;
        for(int& n:nums){
            if(n==0)return 0;
            if(n<0)cntNeg++;
        }
        
        return cntNeg%2==0?1:-1;
    }
};