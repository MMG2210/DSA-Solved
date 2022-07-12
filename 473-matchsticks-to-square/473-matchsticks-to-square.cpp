class Solution {
public:
    int n;
    vector<int> dp;
    
    bool solve(vector<int>& m, int& target, int mask, int i, int sum, int sides){
        if(i==sides)return 1;
        if(dp[mask]!=-1)return dp[mask];
        
        bool res=0;
        for(int j=0;j<n;j++){
            if(mask&1<<j)continue;
            if(m[j]+sum>target)break;
            if(m[j]+sum==target){
                mask^=1<<j;
                res|=solve(m, target, mask, i+1, 0, sides);
                mask^=1<<j;
            }
            else{
                mask^=1<<j;
                res|=solve(m, target, mask, i, sum+m[j], sides);
                mask^=1<<j;
            }
            if(res)break;
        }
        return dp[mask] = res;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(), matchsticks.end(), 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if(!sum || sum%4)return false;
        sum/=4;
        n=matchsticks.size();
        dp.resize(1<<n,-1);
        return solve(matchsticks, sum, 0, 0, 0, 4);
    }
};