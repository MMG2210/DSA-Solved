class Solution {
public:
    
    bool isValid(vector<int>& weights, int mid, int days){
        int curSum=0;
        for(int i=0;i<weights.size();i++){
            curSum+=weights[i];
            if(curSum>mid){
                curSum=weights[i];
                days--;
            }
            
            if(days==0)return false;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=0,r=0,res=INT_MAX;
        for(int& w:weights){r+=w;l=max(l,w);}
        if(days==1)return r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(weights,mid,days)){
                res=mid;
                r=mid-1;
            }
            
            else l=mid+1;
        }
        
        return res;
    }
};