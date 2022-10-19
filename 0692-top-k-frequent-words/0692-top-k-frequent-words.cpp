class Solution {
public:
    struct comp{
        bool operator()(pair<int,string> const& a,pair<int,string> const& b){
            if(a.first==b.first)return a.second>b.second;
            return a.first<b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        priority_queue<pair<int,string>, vector<pair<int,string>>, comp> pq;
        unordered_map<string,int> freq;
        for(auto& s:words){
            freq[s]++;
        }
        for(auto& [s,cnt]:freq){
            pq.push({cnt,s});
        }
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};