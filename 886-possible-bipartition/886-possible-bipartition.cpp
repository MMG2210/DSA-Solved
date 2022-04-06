class Solution {
public:
    bool bfs(vector<vector<int>>& dislikes, int src, vector<int>& groups){
        queue<int> q;
        q.push(src);
        groups[src]=1;
        while(!q.empty()){
            int t=q.front();q.pop();
            for(int &i:dislikes[t]){
                if(groups[i]==-1){
                    groups[i]=1-groups[t];
                    q.push(i);
                }
                else if(groups[i]==groups[t])return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> groups(n+1,-1);
        vector<vector<int> >g(n+1);
        for(auto v:dislikes){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        for(int i=1;i<=n;i++){
            if(groups[i]==-1){
                if(!bfs(g,i,groups))return false;
            }
        }
        return true;
    }
};