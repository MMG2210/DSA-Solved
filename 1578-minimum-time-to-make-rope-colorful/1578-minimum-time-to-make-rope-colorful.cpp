class Solution {
public:
    int minCost(string &s, vector<int>& cost) {
        int  res=0, mx=0, tot=0, n=s.length();
        for(int i=0;i<n;i++){
            if(i>0 && s[i]!=s[i-1]){
                res+=tot-mx;
                tot=mx=0;
            }
            tot+=cost[i];
            mx=max(mx,cost[i]);
        }
        res+=tot-mx;
        return res;
    }
};