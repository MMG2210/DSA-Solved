class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colour(n,-1);
        for(int i=0;i<n;i++){
            if(colour[i]!=-1)continue;
            queue<int> q;
            q.push(i);
            colour[i]=1;
            while(!q.empty()){
                int temp = q.front();q.pop();
                for(int &it:graph[temp]){
                    if(colour[it]==-1){colour[it]=1-colour[temp];q.push(it);}
                    else if(colour[it]==colour[temp])return false;
                }
            }
        }
        return true;
    }
};