class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int& a:arr){
            map[a]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto [e,occ]:map){
            pq.push({occ,e});
        }
        int target = arr.size()/2;
        int res=0;
        while(target>0){
            auto top = pq.top();
            pq.pop();
            target-=top.first;
            res++;
        }
        return res;
    }
};