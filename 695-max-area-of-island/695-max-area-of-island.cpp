class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& grid){
        return i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1;
    }
    int findArea(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& seen){
        if(!isValid(i,j,grid) || seen[i][j])return 0;
        seen[i][j]=true;
        int count=0;
        count+=findArea(grid,i+1,j,seen);
        count+=findArea(grid,i,j+1,seen);
        count+=findArea(grid,i-1,j,seen);
        count+=findArea(grid,i,j-1,seen);
        return count+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0,m=grid.size(),n=grid[0].size();
        vector<vector<bool>> seen(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    if(!seen[i][j])maxi = max(maxi,findArea(grid, i, j,seen));
            }
        }
        return maxi;
    }
};