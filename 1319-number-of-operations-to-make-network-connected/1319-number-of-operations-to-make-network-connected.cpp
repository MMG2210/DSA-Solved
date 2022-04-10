class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int i){
        vis[i]=true;
        for(auto& v:adj[i]){
            if(!vis[v]){
                dfs(adj,vis,v);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        vector<vector<int>> adj(n);
        for(auto& v:connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> vis(n,false);
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                res++;
            }
        }
        return res-1;
    }
};