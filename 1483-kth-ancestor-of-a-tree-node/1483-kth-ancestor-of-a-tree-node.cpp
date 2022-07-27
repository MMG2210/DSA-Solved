class TreeAncestor {
public:
    static const int N=1e5+1,M=20;
    int Par[N][M];
    vector<int> gr[N];
    
    void dfs(int cur, int p){
        Par[cur][0]=p;
        for(int j=1;j<M;j++){
            Par[cur][j]=(Par[cur][j-1]>=0)?Par[Par[cur][j-1]][j-1]:-1;   
        }
        for(auto& x:gr[cur]){
            if(x!=p)dfs(x,cur);
        }
    }
    
    TreeAncestor(int n, vector<int>& parent) {
        // memset(Par,-1,sizeof(Par));
        // for(int i=0;i<7;i++){
        //     if(parent[i]>=0){
        //         gr[parent[i]].push_back(i);
        //         gr[i].push_back(parent[i]);
        //     }
        // }
        // dfs(0,-1);
        for(int i=0;i<n;i++)Par[i][0]=parent[i];
        for(int j=1;j<M;j++){
            for(int i=0;i<n;i++){
                if(Par[i][j-1]==-1)Par[i][j]=-1;
                else Par[i][j]=Par[Par[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j=M-1;j>=0;j--){
            if((k>>j)&1){
                node=Par[node][j];
                if(node<=-1)return node;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */