class Solution {
public:
    int m,t;
    vector<int> dp;
    
    bool solve(int mask, int score){
        if(dp[mask]!=-1)return dp[mask];
        for(int i=0;i<m;i++){
            int cmask=1<<i;
            if(!(mask&cmask)){
                if(score+i+1>=t or solve(mask|cmask,score+i+1)==false)return dp[mask]=true;
            }
        }
        return dp[mask]=0;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        m=maxChoosableInteger;
        t=desiredTotal;
        if((m*(m+1))>>1<t)return false;
        dp.resize(1<<m,-1);
        return solve(0,0);
    }
};