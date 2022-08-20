class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& stations){
        sort(stations.begin(),stations.end());
        int res=0, N=stations.size();
        priority_queue<int> pq;
        for(int i=0;i<=N;i++){
            int dist = i==N? target:stations[i][0];
            while(fuel<dist){
                if(pq.empty())return -1;
                fuel+=pq.top();
                pq.pop();
                res++;
            }
            if(i<N)pq.push(stations[i][1]);
        }
        return res;
    }
};