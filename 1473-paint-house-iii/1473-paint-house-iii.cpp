class Solution {
public:
    int M,N,targetNeighbourhood,max_val = 1000001;
    int dp[101][101][21];
    
    int solve(vector<int> &h, vector<vector<int>>& c, int i, int nbh, int prev){
        if(i==M)return nbh==targetNeighbourhood?0:max_val;
        if(nbh>targetNeighbourhood)return max_val;
        
        if(dp[i][nbh][prev]!=-1)return dp[i][nbh][prev];
        
        int total = max_val;
        //House is already colored
        if(h[i]){
            total = solve(h,c,i+1, nbh + (prev!=h[i]), h[i]);
        }
        //House isn't colored yet
        else{
            int totalColors = c[i].size();
            for(int j=1;j<=totalColors;j++){
                total=min(total, c[i][j-1] + solve(h,c,i+1,nbh+(prev!=j),j));
            }
        }
        
        return dp[i][nbh][prev] = total;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        M=m;
        N=n;
        targetNeighbourhood = target;
        memset(dp,-1,sizeof(dp));
        int res = solve(houses, cost, 0, 0, 0);
        return res==max_val?-1:res;
    }
};