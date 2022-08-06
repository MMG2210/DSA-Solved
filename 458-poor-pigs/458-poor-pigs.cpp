//class Solution {
// public:
//     int MOD=1e9+7;
//     int mpow(int a, int b){
//         int res=1;
//         while(b){
//             if(b&1)res*=a;
//             a*=a;
//             b>>=1;
//         }
//         return res;
//     }
    
//     int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
//         int pigs=0, rounds=minutesToTest/minutesToDie;
//         while(mpow(rounds+1,pigs)<buckets)pigs++;
//         return pigs;
//     }
// };

class Solution {
public:
    int rounds;
    const int MOD=1e9+7;
    int mpow(long long a, int b){
        int res=1;
        while(b){
            if(b&1)res = (res*a)%MOD;
            a*=a;
            a%=MOD;
            b>>=1;
        }
        return res%MOD;
    }
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int low=0, high=buckets, rounds = (minutesToTest/minutesToDie)+1;
        int res=INT_MAX;
        while(low<=high){
            int pigs=(low+high)>>1;
            if(mpow(rounds,pigs)>=buckets){
                res=pigs;
                high=pigs-1;
            }
            else low=pigs+1;
        }
        return res;
    }
};