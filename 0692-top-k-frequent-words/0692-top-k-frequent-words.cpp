class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        priority_queue<pair<int,string>> pq;
        unordered_map<string,int> freq;
        for(auto& s:words){
            freq[s]++;
        }
        for(auto& [s,cnt]:freq){
            pq.push({-cnt,s});
            if(pq.size()>k)pq.pop();
        }
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};