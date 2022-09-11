class Solution {
public:
    int MOD=1e9+7;

    int maxPerformance(int n, vector<int>& spd, vector<int>& eff, int k) {
        long sum=0,best=0;
        vector<pair<int,int>> emp;
        for(int i=0;i<n;i++){
            emp.push_back({eff[i],spd[i]});
        }
        sort(emp.rbegin(),emp.rend());
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto& [e,s]:emp){
            pq.emplace(s);
            sum+=s;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            best = max(best,sum*e);
        }
        return best%MOD;
    }
};