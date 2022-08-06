class Solution {
public:
    int MOD=1e9+7;
    int mpow(int a, int b){
        int res=1;
        while(b){
            if(b&1)res*=a;
            a*=a;
            b>>=1;
        }
        return res;
    }
    
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs=0, rounds=minutesToTest/minutesToDie;
        while(mpow(rounds+1,pigs)<buckets)pigs++;
        return pigs;
    }
};