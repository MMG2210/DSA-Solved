class Solution:
    def rotate(self, a: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(a)
        i = 0
        j=n-1
        while i<j:
            for k in range(0,j-i):
                a[i][i+k],a[i+k][j]=a[i+k][j],a[i][i+k]
                a[i][i+k],a[j][j-k]=a[j][j-k],a[i][i+k]
                a[i][i+k],a[j-k][i]=a[j-k][i],a[i][i+k]
            i+=1
            j-=1