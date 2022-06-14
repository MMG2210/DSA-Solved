#define pii pair<int,int>
#define F first
#define S second
class Solution {
public:
    int M,N;

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        M=mat.size();
        N=mat[0].size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int i=0;i<M;i++){
            int j=0;
            while(j<N && mat[i][j]==1)j++;
            pq.push({j,i});
        }
        
        while(k--){
            auto p = pq.top(); pq.pop();
            res.push_back(p.S);
        }
        
        return res;
    }
};