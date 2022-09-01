class Solution:
    def pacificAtlantic(self, h: List[List[int]]) -> List[List[int]]:
        m,n=len(h),len(h[0])
        pac,atl = set(),set()
        
        def dfs(h,vis,i,j,prev):
            if (i,j) in vis or i<0 or j<0 or i==m or j==n or h[i][j]<prev:
                return
            vis.add((i,j))
            
            dfs(h,vis,i+1,j,h[i][j])
            dfs(h,vis,i-1,j,h[i][j])
            dfs(h,vis,i,j+1,h[i][j])
            dfs(h,vis,i,j-1,h[i][j])
            
        for i in range(m):
            dfs(h,pac,i,0,h[i][0])
            dfs(h,atl,i,n-1,h[i][n-1])
            
        for i in range(n):
            dfs(h,pac,0,i,h[0][i])
            dfs(h,atl,m-1,i,h[m-1][i])
        
        return list(atl.intersection(pac))