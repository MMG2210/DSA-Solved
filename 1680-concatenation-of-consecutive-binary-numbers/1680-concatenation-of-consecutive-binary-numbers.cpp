class Solution {
public:
    int concatenatedBinary(int n) {
        int MOD=1e9+7;
        long res=0;
        for(int i=1;i<=n;i++){
            int len  = 32 - __builtin_clz(i);
            res = ((res<<len)|i)%MOD;
        } 
        return res;
    }
};