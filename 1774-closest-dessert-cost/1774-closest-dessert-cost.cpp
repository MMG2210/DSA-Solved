class Solution {
public:
    int t;
    
    int closest(int a, int b){
        if(a==0)return b;
        if(b==0)return a;
        if(abs(t-a)==abs(t-b))return a<b?a:b;
        return abs(t-a)<abs(t-b)?a:b;
    }
    
    int recur(vector<int>& tC, int i, int cost){
        if(i==tC.size())return cost;
        
        int skip=recur(tC,i+1,cost);
        int take1=recur(tC,i+1,cost+(1*tC[i]));
        int take2=recur(tC,i+1,cost+(2*tC[i]));
        return closest(skip, closest(take1,take2));
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& tC, int target) {
        t=target;
        int res=0;
        for(int i=0;i<baseCosts.size();i++){
            int bc=baseCosts[i];
            res=closest(res, recur(tC,0,bc));
        }
        
        return res;
    }
};