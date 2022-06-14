#define pii pair<int,int>
#define F first
#define S second
class Solution {
public:
    int M,N;
    
    int findFirst0(vector<vector<int>>& mat, int i){
        int l=0,r=N-1,res=N;
        while(l<=r){
            int m = l+(r-l)/2;
            if(!mat[i][m]){
                res=m;
                r=m-1;
            }
            else l=m+1;
        }
        return res;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        M=mat.size();
        N=mat[0].size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int i=0;i<M;i++){
            // int j=0;
            // while(j<N && mat[i][j]==1)j++;
            pq.push({findFirst0(mat,i),i});
        }
        
        while(k--){
            auto p = pq.top(); pq.pop();
            res.push_back(p.S);
        }
        
        return res;
    }
};