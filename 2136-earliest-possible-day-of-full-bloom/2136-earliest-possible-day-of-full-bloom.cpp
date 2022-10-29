#define pii pair<int,int>
#define F first
#define S second
class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        vector<pii> arr;
        for(int i=0;i<pt.size();i++){
            arr.push_back({gt[i],pt[i]});
        }
        int res=0;
        sort(arr.begin(),arr.end());
        for(auto x:arr){
            res = max(res,x.F)+x.S;
        }
        return res;
    }
};