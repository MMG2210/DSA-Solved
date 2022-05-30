class Solution {
public:
    int divide(int dividend, int divisor) {
        long long temp = ((1LL*dividend)/divisor);
        if(temp>INT_MAX)return INT_MAX;
        else if (temp<INT_MIN)return INT_MIN;
        else return (int)temp;
    }
};