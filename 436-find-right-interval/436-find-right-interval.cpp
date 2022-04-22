class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        
        vector<int> res(n,-1);
        vector<pair<vector<int>,int>> v;
        if(n<=1)return res;
        for(int i=0;i<n;i++){
            v.push_back({intervals[i],i});
        }
        sort(v.begin(),v.end());
        
        for(int i=0;i<n;i++){
            
            int l=0,r=n-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if(intervals[i][1]<=v[m].first[0]){
                    r=m-1;
                    res[i]=v[m].second;
                }
                else{
                    l=m+1;
                }
            }
        }
        return res;
    }
};