class Solution {
public:
    int m,n;
    vector<vector<int>> res;
    vector<vector<bool>> atl,pac;
    
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j){
        if(vis[i][j])return;
        vis[i][j]=1;
        if(atl[i][j] && pac[i][j]){
            res.push_back({i,j});
        }
        if(i+1<m && h[i+1][j]>=h[i][j])dfs(h,vis,i+1,j);
        if(i-1>=0 && h[i-1][j]>=h[i][j])dfs(h,vis,i-1,j);
        if(j+1<n && h[i][j+1]>=h[i][j])dfs(h,vis,i,j+1);
        if(j-1>=0 && h[i][j-1]>=h[i][j])dfs(h,vis,i,j-1);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        if(h.empty()){
            return res;
        }
        m=h.size(),n=h[0].size();
        atl = pac = vector<vector<bool>>(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            dfs(h,pac,i,0);
            dfs(h,atl,i,n-1);
        }
        for(int i=0;i<n;i++){
            dfs(h,pac,0,i);
            dfs(h,atl,m-1,i);
        }
        return res;
    }
};