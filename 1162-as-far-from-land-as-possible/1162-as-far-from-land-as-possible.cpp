class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int maxDis=0,m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)q.push({i,j});
        
        while(!q.empty()){
            vector<pair<int,int>> newDis = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
            auto temp = q.front();q.pop();
            for(int i=0;i<4;i++){
                int nx = temp.first + newDis[i].first;
                int ny =temp.second + newDis[i].second;
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==0){
                    q.push({nx,ny});
                    grid[nx][ny]=grid[temp.first][temp.second]+1;
                    maxDis = max(maxDis,grid[nx][ny]);
                }
            }
        }
        return maxDis>0? maxDis-1:-1;
    }
};