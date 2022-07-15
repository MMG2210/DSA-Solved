//class Solution {
// public:
//     bool isValid(int i, int j, vector<vector<int>>& grid){
//         return i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1;
//     }
//     int findArea(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& seen){
//         if(!isValid(i,j,grid) || seen[i][j])return 0;
//         seen[i][j]=true;
//         int count=0;
//         count+=findArea(grid,i+1,j,seen);
//         count+=findArea(grid,i,j+1,seen);
//         count+=findArea(grid,i-1,j,seen);
//         count+=findArea(grid,i,j-1,seen);
//         return count+1;
//     }
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int maxi=0,m=grid.size(),n=grid[0].size();
//         vector<vector<bool>> seen(m,vector<bool>(n,false));
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1)
//                     if(!seen[i][j])maxi = max(maxi,findArea(grid, i, j,seen));
//             }
//         }
//         return maxi;
//     }
// };
// This is done through the use of basic DFS method similar to no of islands problem.

class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int findPar(int x){
        if(par[x]==x)return x;
        return par[x]=findPar(par[x]);
    }
    
    void merge(int x, int y){
        int px=findPar(x), py=findPar(y);
        if(rank[px]>rank[py]){
            par[py]=px;
            rank[px]+=rank[py];
        }
        else{
            par[px]=py;
            rank[py]+=rank[px];
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid[0].size(), m=grid.size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                par.push_back(i*n + j);
                rank.push_back(1);
            }
        }
        bool hasOne=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    hasOne=true;
                    if(i+1<m && grid[i+1][j]==1){
                        int p1=findPar(i*n+j);
                        int p2=findPar((i+1)*n+j);
                        if(p1!=p2){
                            merge(i*n+j, (i+1)*n+j);
                        }
                    }
                    if(j+1<n && grid[i][j+1]==1){
                        int p1=findPar(i*n+j);
                        int p2=findPar(i*n+j+1);
                        if(p1!=p2){
                            merge(i*n+j, i*n+j+1);
                        }
                    }
                }
            }
        }
        
        if(hasOne)return *max_element(rank.begin(),rank.end());
        return 0;
    }
};