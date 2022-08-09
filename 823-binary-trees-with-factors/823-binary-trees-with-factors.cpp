#define ll long long
class Solution {
public:
    const int MOD=1e9+7;
    int numFactoredBinaryTrees(vector<int>& A) {
        ll res=0;
        sort(A.begin(),A.end());
        unordered_map<int,ll> dp;
        for(int i=0;i<A.size();i++){
            dp[A[i]]=1;
            for(int j=0;j<i;j++){
                if(A[i]%A[j]==0){
                    dp[A[i]] = (dp[A[i]] + dp[A[j]]*dp[A[i]/A[j]])%MOD;
                }
            }
            res = (res+dp[A[i]])%MOD;
        }
        return res;
    }
};