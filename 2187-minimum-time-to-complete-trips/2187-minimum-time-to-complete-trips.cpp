class Solution {
public:
    bool canComplete(vector<int>& time, int totalTrips, long long arbTime){
        //int completedTrips=0;
        for(int i=0;i<time.size();i++){
            totalTrips -= arbTime/time[i];
            if(totalTrips<=0)return true;
        }
        return false;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long res=0;
        long long l=0;
        //long long r=1e14+1;
        long long r=1ll*(*min_element(time.begin(), time.end()))*totalTrips;
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(canComplete(time, totalTrips, mid)){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};