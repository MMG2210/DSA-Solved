class Solution {
public:
    bool vis[101][101][101] = {};
    bool hasValidPath(vector<vector<char>>& grid, int i=0, int j=0, int para=0) {
        int m=grid.size(), n=grid[0].size();
        
        para+=grid[i][j]=='('?1:-1;
        
        if(para<0 || para>(m+n)/2 || vis[i][j][para])return false;
        vis[i][j][para]=true;
        
        if(i==m-1 && j==n-1 && para==0)return true;
        
        else if(i<m-1 && hasValidPath(grid,i+1,j,para))return true;
        
        else if (j<n-1 && hasValidPath(grid,i,j+1,para))return true;
        
        return false;
    }
};