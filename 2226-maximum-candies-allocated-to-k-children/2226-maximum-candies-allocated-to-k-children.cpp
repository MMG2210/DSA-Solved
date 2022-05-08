class Solution {
public:
    
    bool isValid(vector<int>& candies, long long k, int minCandy){
        int n = candies.size(), sum=candies[0];
        long long children=1;
        
        for(int i=0;i<n;i++){
            children+=candies[i]/minCandy;
            if(children>k)return true;
        }
        
        return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int maxi = 0;
        for(int& c:candies)maxi=max(maxi,c);
        int high = maxi, low=1;
        int res=0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isValid(candies, k, mid)){
                res=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        
        return res;
    }
};