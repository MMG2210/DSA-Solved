class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i, int j){
        return i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<int,int>> rotten;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)rotten.push({i,j});
            }
        }
        bool anyFresh=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)anyFresh=true;
            }
        }
        int mins=-1;
        if(!anyFresh)return 0;
        while(!rotten.empty()){
            int s = rotten.size();
            for(int it=0;it<s;it++){
                auto temp = rotten.front();rotten.pop();
                int i=temp.first,j=temp.second;
                if(isValid(grid,i+1,j)){rotten.push({i+1,j});grid[i+1][j]=2;}
                if(isValid(grid,i-1,j)){rotten.push({i-1,j});grid[i-1][j]=2;}
                if(isValid(grid,i,j+1)){rotten.push({i,j+1});grid[i][j+1]=2;}
                if(isValid(grid,i,j-1)){rotten.push({i,j-1});grid[i][j-1]=2;}
            }
            mins++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return mins;
    }
};