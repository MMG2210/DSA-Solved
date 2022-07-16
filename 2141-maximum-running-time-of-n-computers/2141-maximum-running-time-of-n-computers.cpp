#define ll long long
class Solution {
public:
    bool isValid(int& n, vector<int>& batteries, ll mid){
        long long total=n*mid;
        for(ll bt:batteries){
            total-=min(bt,mid);
        }
        return total<=0;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        ll res=0, l=0, r, sum=accumulate(batteries.begin(), batteries.end(),0LL);
        r=sum;
        while(l<=r){
            ll mid = l+(r-l)/2;
            if(isValid(n, batteries, mid)){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return res;
    }
};