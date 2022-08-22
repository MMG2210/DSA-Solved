class Solution {
public:
    bool isPowerOfFour(int n) {
        long long i=1;
        while(n>i)i*=4;
        return n==i;
    }
};