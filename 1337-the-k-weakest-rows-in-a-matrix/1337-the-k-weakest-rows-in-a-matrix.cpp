#define pii pair<int,int>
#define F first
#define S second
class Solution {
public:
    int M,N;
    int findLast1(vector<vector<int>>& mat, int i){
        int l=0,r=N-1,res=0;
        while(l<=r){
            int m = l+(r-l)/2;
            if(mat[i][m]==1){
                res=m;
                l=m+1;
            }
            else r=m-1;
        }
        return r;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        M=mat.size();
        N=mat[0].size();
        priority_queue<pii> pq;
        for(int i=0;i<M;i++){
            pq.push({findLast1(mat,i),i});
            if(pq.size()>k)pq.pop();
        }
        
        while(k--){
            auto p = pq.top(); pq.pop();
            res.push_back(p.S);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};