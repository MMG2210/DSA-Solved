#define pii pair<int,int>
#define F first
#define S second
class Solution {
public:
    static bool cmp(pii& a, pii& b){
        return a.F>b.F;
    }
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        vector<pii> arr;
        for(int i=0;i<pt.size();i++){
            arr.push_back({gt[i],pt[i]});
        }
        int res=0,days=0;
        sort(arr.begin(),arr.end(), cmp);
        for(int i=0;i<arr.size();i++){
            days+=arr[i].S;
            res = max(res,days+arr[i].F);
        }
        return res;
    }
};