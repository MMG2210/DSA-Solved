class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MOD = 1000000007
        res = 0
        for i in range(1,n+1):
            res = ((res<<i.bit_length())|i)%MOD
        return res