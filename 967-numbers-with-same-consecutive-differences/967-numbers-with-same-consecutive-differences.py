class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        res = [1,2,3,4,5,6,7,8,9]
        
        for i in range(0,n-1):
            res2=  []
            for x in res:
                y = x%10;
                if y+k<10 :
                    res2.append(x*10+y+k)
                if k>0 and y-k>=0:
                    res2.append(x*10+y-k)
            res=res2
            
        return res