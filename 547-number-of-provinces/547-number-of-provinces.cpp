class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool>& vis,int start){
        for(int j=0;j<isConnected.size();j++){
            if(vis[j])continue;
            else if(!vis[j] && isConnected[start][j]==1){
                vis[j]=true;
                dfs(isConnected,vis,j);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int province=0, n=isConnected.size();
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                dfs(isConnected,vis,i);
                province++;
            }
        }
        return province;
    }
};