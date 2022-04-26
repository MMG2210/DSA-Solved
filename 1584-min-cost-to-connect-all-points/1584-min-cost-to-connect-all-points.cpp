class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>> adj[n];
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
            }
        }
        
        vector<bool> vis(n,false);
        int falseCount=n;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> edges;
        edges.push({0,0});
        
        while(!edges.empty() && falseCount){
            pair<int,int> t=edges.top(); edges.pop();
            int node=t.second;
            int cost=t.first;
            if(vis[node])continue;
            vis[node]=true;
            falseCount--;
            res+=cost;
            for(auto& it:adj[node]){
                if(!vis[it.first])edges.push({it.second,it.first});
            }
        }
        
        return res;
    }
};