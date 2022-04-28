#define pii pair<int,pair<int,int>>
class Solution {
public:
    int dx[5]={-1,0,1,0,-1};
    
    int minimumEffortPath(vector<vector<int>>& h) {
        int row=h.size(),col=h[0].size();
        vector<vector<int>> dist(row,vector<int>(col,INT_MAX));
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            pii temp=pq.top(); pq.pop();
            int d=temp.first, r=temp.second.first, c=temp.second.second;
            
            if(r==row-1 && c==col-1)return d;
            
            for(int i=0;i<4;i++){
                int nx=r+dx[i], ny=c+dx[i+1];
                if(nx==row || ny==col || nx<0 || ny<0)continue;
                
                int new_d=max(abs(h[r][c]-h[nx][ny]),d);
                if(new_d<dist[nx][ny]){
                    dist[nx][ny]=new_d;
                    pq.push({new_d,{nx,ny}});
                }
            }
        }
        
        return 0;
    }
};