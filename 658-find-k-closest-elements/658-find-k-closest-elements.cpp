#define pii pair<int,int>
#define F first
#define S second
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        priority_queue<pii> pq;
        for(int& i:arr){
            if(pq.size()<k)pq.push({abs(i-x),i});
            else{
                if(pq.top().F>abs(i-x) or pq.top().F==abs(i-x) && pq.top().S>i){
                    pq.pop();
                    pq.push({abs(i-x),i});
                }
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().S);
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};