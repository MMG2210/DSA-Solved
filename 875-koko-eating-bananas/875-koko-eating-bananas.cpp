class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int& p:piles)maxi=max(p,maxi);
        int l=1,r=maxi;
        while(l<=r){
            int m=l+(r-l)/2;
            int totalHours=0;
            for(int p:piles)totalHours+=(p+m-1)/m;
            if(totalHours>h)l=m+1;
            else r=m-1;
        }
        return l;
    }
};