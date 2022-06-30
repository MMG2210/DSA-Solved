class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<int> arr{1,2,3,4,5,6};
    int mod;
    long solve(int n, int last, int prevLast, int i) {
        if(i == n) return 1;
        
        //  avoid to check when we have choosen less than 2 element only
        long res = min(last, prevLast)<0 ? -1 :dp[last][prevLast][i];
        if(res!=-1) return res;
        res = 0;
        for(int &j:arr) {
            //  handle the cases
            if(j == last || j == prevLast || (last!=-1 && (__gcd(j, last)!=1))) continue;
            
            //  handle integer overflow case
            res=(res+solve(n, j, last, i+1))%mod;
        }
        if(min(last, prevLast)>=0) {
            dp[last][prevLast][i]=res;
        }
        return res;
    }
    
    int distinctSequences(int n) {
     mod = 1000000007;
     dp.resize(7, vector<vector<int>>(7, vector<int>(n+1, -1)));
     return solve(n, -1, -1, 0);   
    }
};