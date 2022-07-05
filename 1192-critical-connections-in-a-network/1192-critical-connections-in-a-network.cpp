#define pb push_back
class Solution {
public:
    
//     int dfs(int start,vector<vector<int>>& adj,vector<int>& ex,vector<bool>& vis){
//         vis[start]=true;
//         int cnt=1;
//         for(auto& a:adj[start]){
//             int ex1=ex[0],ex2=ex[1];
//             if((start==ex1 && a==ex2) || (start==ex2 && a==ex1))continue;
//             if(!vis[a]){
//                 cnt+=dfs(a,adj,ex,vis);
//             }
//         }
//         return cnt;
//     }
    
//     vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
//        vector<vector<int>> adj(n);
//         for(auto& c:connections){
//             adj[c[0]].push_back(c[1]);
//             adj[c[1]].push_back(c[0]);
//         }
//         vector<vector<int>> res;
//         for(int i=0;i<connections.size();i++){
//             vector<int> exclude(2);
//             vector<bool> vis(n,false);
//             exclude[0]=connections[i][0];
//             exclude[1]=connections[i][1];
//             int count = dfs(0,adj,exclude,vis);
//             if(count<n)res.push_back(exclude);
//         }
//         return res;
//     } Straight-up DFS TC - O(E*(V+E)) effectively making it a Quadratic time solution
    
    void tarjans(int curr, int parent, int time, vector<vector<int>>& adj, vector<int>& low, vector<vector<int>>& res){
        low[curr]=time++;
        for(auto& x:adj[curr]){
            if(x==parent)continue;
            if(low[x]==0){
                tarjans(x,curr,time,adj,low,res);
            }
            low[curr]=min(low[curr],low[x]);
            if(low[x]==time){
                res.push_back({curr,x});
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       vector<vector<int>> adj(n);
        for(auto& c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<vector<int>> res;
        vector<int> low(n);
        tarjans(0,-1,1,adj,low,res);
        return res;
    }
    //Tarjan's Algorithm uses time complexity of O(E+V) effectively making it a Linear time solution. 
};