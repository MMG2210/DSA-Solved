class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        int res=0,n=p.size(),def=INT_MIN;
        sort(p.begin(),p.end(),comp);
        for(int i=n-1;i>=0;i--){
            if(p[i][1]<def){
                res++;
            }
            else def=p[i][1];
        }
        return res;
    }
};