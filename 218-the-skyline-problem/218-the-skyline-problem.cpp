class Solution {
public:
    struct sky{
        int x, h;
        bool start;
        sky(int x, int h, bool start) : x(x), h(h), start(start){}
    };
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<sky> sl;
        for(auto& b:buildings){
            sl.push_back(sky(b[0],b[2],true));
            sl.push_back(sky(b[1],b[2],false));
        }
        sort(sl.begin(),sl.end(),[](sky& a, sky& b){
            if(a.x!=b.x)return a.x<b.x;
            if(a.start && b.start)return a.h>b.h;
            if(a.start)return true;
            if(b.start)return false;
            return a.h<b.h;
        });
        map<int,int,greater<int>> pq;
        vector<vector<int>> res;
        int prevMax=0;
        pq[0]=1;
        for(int i=0;i<sl.size();i++){
            if(sl[i].start){
                pq[sl[i].h]++;
            }
            else{
                pq[sl[i].h]--;
                if(pq[sl[i].h]==0)pq.erase(sl[i].h);
            }
            auto bg = pq.begin();
            if(bg->first!=prevMax){
                res.push_back({sl[i].x,bg->first});
                prevMax=bg->first;
            }
        }
        return res;
    }
};