class Solution {
public:
    int n;
    map<pair<int,int>,pair<int,int>> dp;
    
    pair<int,int> solve(vector<int>& arr,int l,int r){
        if(l==r){
            return {0,arr[l]};
        }
        if(dp.find({l,r})!=dp.end())return dp[{l,r}];
        
        pair<int,int> res={1e9,0};
        for(int i=l;i<r;i++){
            auto leftRes=solve(arr,l,i);
            auto rightRes=solve(arr,i+1,r);
            int cost=leftRes.first+rightRes.first+(leftRes.second*rightRes.second);
            if(cost<res.first){
                res.first=cost;
                res.second=max(leftRes.second, rightRes.second);
            }
        }
        return dp[{l,r}] = res;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        n=arr.size();
        return solve(arr,0,n-1).first;
    }
};