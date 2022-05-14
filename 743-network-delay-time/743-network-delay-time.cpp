class Solution {
public:
    int dijkstra(vector<int>& dist,vector<vector<pair<int,int>>>& adj, int& n, int& k){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int w=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto& a:adj[node]){
                if(dist[a.first]>(w+a.second)){
                    dist[a.first]=w+a.second;
                    pq.push({dist[a.first],a.first});
                }
            }
        }
        
        int res=0;
        for(int i=1;i<=n;i++){
            res=max(res,dist[i]);
        }
        
        return res==1e9?-1:res;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e9);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        
        return dijkstra(dist,adj,n,k);
    }
};